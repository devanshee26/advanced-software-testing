#!/bin/bash

# Clean up previous coverage data

# Function to generate coverage for a specific relation
generate_coverage() {
    rm -rf *.gc*
    rm -rf coverage_*.*
    test="$1"
    relation="$2"
    rm -rf ./CoverageReports/MT_Coverage_Analysis/R${relation}_CoverageReport/R${relation}_${test}
    mkdir ./CoverageReports/MT_Coverage_Analysis/R${relation}_CoverageReport/R${relation}_${test}
    executable="./SetCover_MT_TestSuite_Coverage_Analysis/Relation${relation}/SetCover_MT_Relation${relation}_${test}_Exec"
    
    # Compile with coverage flags
    g++ -std=c++14 -fprofile-arcs -ftest-coverage -o "${executable}" SetCover.c "./SetCover_MT_TestSuite_Coverage_Analysis/Relation${relation}/SetCover_MT_Relation${relation}_${test}.cpp" $(pkg-config --cflags --libs gtest) -pthread -lgtest -lgtest_main -lpthread
    
    # Execute the program
    "${executable}"
    
    # Generate coverage data
    gcov SetCover.c
    
    # Generate HTML coverage report
    gcovr -r . --html --html-details -o "./CoverageReports/MT_Coverage_Analysis/R${relation}_CoverageReport/R${relation}_${test}/coverage_report.html"
}

# Loop through relations and generate coverage for each
for relation in {1..4}; do
    for test_number in {1..9}; do
        generate_coverage "$test_number" "$relation"
    done
done
