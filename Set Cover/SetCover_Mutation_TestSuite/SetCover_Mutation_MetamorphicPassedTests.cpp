#include "../SetCover.h"
#include <gtest/gtest.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include<stdio.h>
#include <setjmp.h>
#include <signal.h>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

bool areVectorsEqual(const std::vector<int>& v1, const std::vector<int>& v2) {
    // Check if the sizes are equal
    if (v1.size() != v2.size()) {
        return false;
    }

    // Iterate through each vector element
    for (size_t i = 0; i < v1.size(); ++i) {
        // Check if the elements match
        if (v1[i] != v2[i]) {
            return false;
        }
    }

    // Vectors are equal
    return true;
}

bool areVectorOfVectorsEqual(const std::vector<std::vector<int> >& vec1, const std::vector<std::vector<int> >& vec2) {
    // Check if the sizes are equal
    if (vec1.size() != vec2.size()) {
        return false;
    }

    for (size_t i = 0; i < vec1.size(); ++i) {
        bool anyTrue = false;
        for (size_t j = 0; j < vec2.size(); ++j) {
            // std::cout << "comparing ";
            // for (int number : vec1[i]) {
            //     std::cout << number << " ";
            // }
            // std::cout << "with ";
            // for (int number : vec2[j]) {
            //     std::cout << number << " ";
            // }
            // std::cout << std::endl;
            if (areVectorsEqual(vec1[i], vec2[j])) {
                anyTrue = true;
                break;
            }
        }
        if(!anyTrue){
            return false;
        }
    }
    return true;
}

bool isSame(string s1, string s2) {
    std::string inputString1 = s1;
    std::string inputString2 = s2;

    // Create a vector to store arrays of numbers
    std::vector< std::vector<int> > arrayOfArrays1;
    std::vector< std::vector<int> > arrayOfArrays2;
    // Create a string stream to process the input string
    std::istringstream iss1(inputString1);
    std::istringstream iss2(inputString2);

    // Skip the first line
    std::string line;
    std::getline(iss1, line);
    // std::getline(iss1, line);
    // std::getline(iss2, line);
    std::getline(iss2, line);

    // Process each line
    while (std::getline(iss1, line)) {
        // Create a vector to store numbers in the current line
        std::vector<int> numbers;

        // Create a string stream for the current line
        std::istringstream lineStream(line);

        // Skip the first 4 characters
        lineStream.ignore(4);

        // Process numbers in the current line
        int number;
        while (lineStream >> number) {
            numbers.push_back(number);
        }

        // Add the vector of numbers to the array of arrays
        arrayOfArrays1.push_back(numbers);
    }

    while (std::getline(iss2, line)) {
        // Create a vector to store numbers in the current line
        std::vector<int> numbers;

        // Create a string stream for the current line
        std::istringstream lineStream(line);

        // Skip the first 4 characters
        lineStream.ignore(4);

        // Process numbers in the current line
        int number;
        while (lineStream >> number) {
            numbers.push_back(number);
        }

        // Add the vector of numbers to the array of arrays
        arrayOfArrays2.push_back(numbers);
    }

    // // Print the result
    // for (const auto& array : arrayOfArrays1) {
    //     for (int number : array) {
    //         std::cout << number << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // // Print the result
    // for (const auto& array : arrayOfArrays2) {
    //     for (int number : array) {
    //         std::cout << number << " ";
    //     }
    //     std::cout << std::endl;
    // }
    for (auto& vec : arrayOfArrays1) {
        std::sort(vec.begin(), vec.end());
    }

    for (auto& vec : arrayOfArrays2) {
        std::sort(vec.begin(), vec.end());
    }

    // printf("gi\n");

    // // Print the result
    // for (const auto& array : arrayOfArrays1) {
    //     for (int number : array) {
    //         std::cout << number << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // // Print the result
    // for (const auto& array : arrayOfArrays2) {
    //     for (int number : array) {
    //         std::cout << number << " ";
    //     }
    //     std::cout << std::endl;
    // }

    bool allVectorsEqual = areVectorOfVectorsEqual(arrayOfArrays1, arrayOfArrays2);
    return allVectorsEqual;
}

jmp_buf jump_buffer;

void handle_signal(int sig) {
    longjmp(jump_buffer, 1);
}

void register_signal_handler() {
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGSEGV, &sa, nullptr);
}

class SetCover_Mutation_MetamorphicPassedTests : public ::testing::Test {
public:
    // Flag to track whether any test case has failed
    static bool anyTestCasePassed;
    static bool aTestFailed;
    void SetUp() override {
        // Register the signal handler at the beginning of each tes
        register_signal_handler();
    }

    void TearDown() override {
        // Reset signal handler to default at the end of each test
        signal(SIGSEGV, SIG_DFL);
        printf("test if works : %d\n", ::testing::Test::HasFailure() ? 1 : 0);
        // Check if the current test case has failed and set the flag accordingly
        if (!(::testing::Test::HasFailure())) {
            anyTestCasePassed = true;
            printf("tear down passed %d\n", anyTestCasePassed ? 1 : 0);
        }
        if (::testing::Test::HasFailure()) {
            aTestFailed = true;
            printf("tear down failed %d\n", aTestFailed ? 1 : 0);
        }
    }
};

//metamorphic relation 1
// Test case 1
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase1) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_1.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_1.txt";

        // Run SetCover function
        testing::internal::CaptureStdout();  // Redirect stdout to a buffer
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 2
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase2) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_2.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_1.txt";

        // Run SetCover function
        testing::internal::CaptureStdout();  // Redirect stdout to a buffer
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 3
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase3) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_3.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_1.txt";

        // Run SetCover function
        testing::internal::CaptureStdout();  // Redirect stdout to a buffer
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 4
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase4) {  
    register_signal_handler();  
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_4.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_1.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 5
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase5) {  
    register_signal_handler();  
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_5.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_1.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 6
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase6) {   
    register_signal_handler(); 
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_6.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_1.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 7
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase7) { 
    register_signal_handler();   
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_7.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_1.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 8
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase8) {    
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_8.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_1.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 9
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase9) { 
    register_signal_handler();   
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_9.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_1.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

//meamorphic relation2
// Test case 10
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase10) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_10.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_2.txt";

        // Run SetCover function
        testing::internal::CaptureStdout();  // Redirect stdout to a buffer
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 11
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase11) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_11.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_2.txt";

        // Run SetCover function
        testing::internal::CaptureStdout();  // Redirect stdout to a buffer
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 12
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase12) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_12.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_2.txt";

        // Run SetCover function
        testing::internal::CaptureStdout();  // Redirect stdout to a buffer
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 13
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase13) {  
    register_signal_handler();  
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_13.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_2.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 14
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase14) {  
    register_signal_handler();  
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_14.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_2.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 15
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase15) {   
    register_signal_handler(); 
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_15.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_2.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 16
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase16) { 
    register_signal_handler();   
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_16.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_2.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 17
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase17) {    
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_17.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_2.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 18
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase18) { 
    register_signal_handler();   
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_18.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_2.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

//meamorphic relation3
// Test case 19
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase19) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_19.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_3.txt";

        // Run SetCover function
        testing::internal::CaptureStdout();  // Redirect stdout to a buffer
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 20
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase20) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_20.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_3.txt";

        // Run SetCover function
        testing::internal::CaptureStdout();  // Redirect stdout to a buffer
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 21
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase21) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_21.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_3.txt";

        // Run SetCover function
        testing::internal::CaptureStdout();  // Redirect stdout to a buffer
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 22
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase22) {  
    register_signal_handler();  
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_22.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_3.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 23
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase23) {  
    register_signal_handler();  
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_23.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_3.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 24
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase24) {   
    register_signal_handler(); 
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_24.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_3.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 25
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase25) { 
    register_signal_handler();   
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_25.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_3.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 26
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase26) {    
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_26.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_3.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 27
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase27) { 
    register_signal_handler();   
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_27.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_3.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

//meamorphic relation4
// Test case 28
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase28) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_28.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_4.txt";

        // Run SetCover function
        testing::internal::CaptureStdout();  // Redirect stdout to a buffer
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 29
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase29) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_29.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_4b.txt";

        // Run SetCover function
        testing::internal::CaptureStdout();  // Redirect stdout to a buffer
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 30
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase30) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_30.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_4b.txt";

        // Run SetCover function
        testing::internal::CaptureStdout();  // Redirect stdout to a buffer
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 31
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase31) {  
    register_signal_handler();  
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_31.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_4b.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 32
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase32) {  
    register_signal_handler();  
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_32.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_4b.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 33
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase33) {   
    register_signal_handler(); 
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_33.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_4b.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 34
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase34) { 
    register_signal_handler();   
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_34.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_4b.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 35
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase35) {    
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_35.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_4b.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 36
TEST_F(SetCover_Mutation_MetamorphicPassedTests, TestCase36) { 
    register_signal_handler();   
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/MetamorphicAllPassed/test_36.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_4b.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}


// Add more test cases as needed
int main(int argc, char **argv) {
    ::testing::InitGoogleTest_F(&argc, argv); 
    int result = RUN_ALL_TESTS();

    bool a_test_failed = SetCover_Mutation_EachBlockPassedTests::aTestFailed;
    printf(" a test failed  %d\n", a_test_failed ? 1 : 0);

    return SetCover_Mutation_EachBlockPassedTests::aTestFailed ? 1 : 0;
}