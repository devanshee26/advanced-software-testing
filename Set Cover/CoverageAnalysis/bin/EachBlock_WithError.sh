#!/bin/bash

# Function to generate coverage for a specific relation
generate_coverage() {
    rm -rf *.gc*
    rm -rf coverage_*.*
    test="$1"

    rm -rf ../../CoverageReports/CoverageAnalysis/CP/Each_WithError/Test_${test}/*
    mkdir ../../CoverageReports/CoverageAnalysis/CP/Each_WithError/Test_${test} 
    executable="../CP/BaseBlock_WithError/SetCover_CP_EachBlock_${test}_Exec"
    
    # Compile with coverage flags
    g++ -std=c++14 -fprofile-arcs -ftest-coverage -o "${executable}" SetCover.c "../CP/EachBlock_WithError/SetCover_CP_EachBlock_ErrorBlocks_${test}.cpp" $(pkg-config --cflags --libs gtest) -pthread -lgtest -lgtest_main -lpthread
    sleep 6
    # Execute the program
    "${executable}"
    sleep 10
    # Generate coverage data
    gcov SetCover.c
    
    # Generate HTML coverage report
    gcovr -r . --html --html-details -o "../../CoverageReports/CoverageAnalysis/CP/Each_WithError/Test_${test}/coverage_report.html"
}

# Loop through tests and generate coverage for each
for test_number in {1..11}; do
    generate_coverage "$test_number"
done
