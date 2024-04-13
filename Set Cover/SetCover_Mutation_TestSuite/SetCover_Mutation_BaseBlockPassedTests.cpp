#include "SetCover.h"
#include <gtest/gtest.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include<stdio.h>
#include <setjmp.h>
#include <signal.h>

jmp_buf jump_buffer;

class SetCover_Mutation_BaseBlockPassedTests : public ::testing::Test {
public:
    // Flag to track whether any test case has failed
    static bool anyTestCasePassed;
    static bool aTestFailed;

    // SetUp will be called before each test case
    void SetUp() override {
    }

    // TearDown will be called after each test case
    void TearDown() override {
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

bool SetCover_Mutation_BaseBlockPassedTests::anyTestCasePassed = false;
bool SetCover_Mutation_BaseBlockPassedTests::aTestFailed = false;

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


// Test case 1
TEST_F(SetCover_Mutation_BaseBlockPassedTests, TestCase1) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/BaseBlockAllPassed/test_1.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MutationTesting/BaseBlockAllPassed/output_1.txt";

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
        EXPECT_EQ(actualOutput, expectedOutputBuffer.str());
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 2
TEST_F(SetCover_Mutation_BaseBlockPassedTests, TestCase2) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/BaseBlockAllPassed/test_2.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MutationTesting/BaseBlockAllPassed/output_2.txt";

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
        EXPECT_EQ(actualOutput, expectedOutputBuffer.str());
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 3
TEST_F(SetCover_Mutation_BaseBlockPassedTests, TestCase3) {  
    register_signal_handler();  
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/BaseBlockAllPassed/test_3.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MutationTesting/BaseBlockAllPassed/output_3.txt";

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
        EXPECT_EQ(actualOutput, expectedOutputBuffer.str());
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 4
TEST_F(SetCover_Mutation_BaseBlockPassedTests, TestCase4) {  
    register_signal_handler();  
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/BaseBlockAllPassed/test_4.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MutationTesting/BaseBlockAllPassed/output_4.txt";

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
        EXPECT_EQ(actualOutput, expectedOutputBuffer.str());
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 5
TEST_F(SetCover_Mutation_BaseBlockPassedTests, TestCase5) {   
    register_signal_handler(); 
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/BaseBlockAllPassed/test_5.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MutationTesting/BaseBlockAllPassed/output_5.txt";

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
        EXPECT_EQ(actualOutput, expectedOutputBuffer.str());
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 6
TEST_F(SetCover_Mutation_BaseBlockPassedTests, TestCase6) { 
    register_signal_handler();   
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/BaseBlockAllPassed/test_6.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MutationTesting/BaseBlockAllPassed/output_6.txt";

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
        EXPECT_EQ(actualOutput, expectedOutputBuffer.str());
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 7
TEST_F(SetCover_Mutation_BaseBlockPassedTests, TestCase7) {    
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/BaseBlockAllPassed/test_7.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MutationTesting/BaseBlockAllPassed/output_7.txt";

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
        EXPECT_EQ(actualOutput, expectedOutputBuffer.str());
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 8
TEST_F(SetCover_Mutation_BaseBlockPassedTests, TestCase8) { 
    register_signal_handler();   
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/BaseBlockAllPassed/test_8.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MutationTesting/BaseBlockAllPassed/output_8.txt";

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
        EXPECT_EQ(actualOutput, expectedOutputBuffer.str());
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 9
TEST_F(SetCover_Mutation_BaseBlockPassedTests, TestCase9) {   
    register_signal_handler(); 
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/BaseBlockAllPassed/test_9.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MutationTesting/BaseBlockAllPassed/output_9.txt";

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
        EXPECT_EQ(actualOutput, expectedOutputBuffer.str());
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 10
TEST_F(SetCover_Mutation_BaseBlockPassedTests, TestCase10) { 
    register_signal_handler();   
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/BaseBlockAllPassed/test_10.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MutationTesting/BaseBlockAllPassed/output_10.txt";

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
        EXPECT_EQ(actualOutput, expectedOutputBuffer.str());
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Base block with error passed
// Test case 11
TEST_F(SetCover_Mutation_BaseBlockPassedTests, TestCase11) {  
    register_signal_handler();  
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/BaseBlockAllPassed/test_11.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MutationTesting/BaseBlockAllPassed/output_11.txt";

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
        EXPECT_EQ(actualOutput, expectedOutputBuffer.str());
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 12
TEST_F(SetCover_Mutation_BaseBlockPassedTests, TestCase12) { 
    register_signal_handler();   
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/BaseBlockAllPassed/test_12.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MutationTesting/BaseBlockAllPassed/output_12.txt";

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
        EXPECT_EQ(actualOutput, expectedOutputBuffer.str());
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 13
TEST_F(SetCover_Mutation_BaseBlockPassedTests, TestCase13) {    
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/BaseBlockAllPassed/test_13.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MutationTesting/BaseBlockAllPassed/output_13.txt";

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
        EXPECT_EQ(actualOutput, expectedOutputBuffer.str());
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}


int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv); 
    int result = RUN_ALL_TESTS();

    bool a_test_failed = SetCover_Mutation_BaseBlockPassedTests::aTestFailed;
    printf(" a test failed  %d\n", a_test_failed ? 1 : 0);

    return SetCover_Mutation_BaseBlockPassedTests::aTestFailed ? 1 : 0;
}