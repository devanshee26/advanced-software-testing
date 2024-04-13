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

class SetCover_Mutation_EachBlockPassedTests : public ::testing::Test {
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

bool SetCover_Mutation_EachBlockPassedTests::anyTestCasePassed = false;

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

// each block without error passed
// Test case 1
TEST_F(SetCover_Mutation_EachBlockPassedTests, TestCase1) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/EachBlockAllPassed/test_1.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MutationTesting/EachBlockAllPassed/output_1.txt";

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
TEST_F(SetCover_Mutation_EachBlockPassedTests, TestCase2) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/EachBlockAllPassed/test_2.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MutationTesting/EachBlockAllPassed/output_2.txt";

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
TEST_F(SetCover_Mutation_EachBlockPassedTests, TestCase3) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/EachBlockAllPassed/test_3.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MutationTesting/EachBlockAllPassed/output_3.txt";

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

// Test case 4
TEST_F(SetCover_Mutation_EachBlockPassedTests, TestCase4) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/EachBlockAllPassed/test_4.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MutationTesting/EachBlockAllPassed/output_4.txt";

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

// Test case 5
TEST_F(SetCover_Mutation_EachBlockPassedTests, TestCase5) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/EachBlockAllPassed/test_5.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MutationTesting/EachBlockAllPassed/output_5.txt";

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

// each block with error passed
// Test case 6
TEST_F(SetCover_Mutation_EachBlockPassedTests_WithErrorBlocks, TestCase6) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MutationTesting/EachBlockAllPassed/test_6.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MutationTesting/EachBlockAllPassed/output_6.txt";

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

// Add more test cases as needed
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    int result = RUN_ALL_TESTS();

    bool a_test_failed = SetCover_Mutation_EachBlockPassedTests::aTestFailed;
    printf(" a test failed  %d\n", a_test_failed ? 1 : 0);

    return SetCover_Mutation_EachBlockPassedTests::aTestFailed ? 1 : 0;
}