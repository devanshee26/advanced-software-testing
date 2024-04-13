#!/bin/sh

provided=22

i=0
valid_mutants=0
total_survived=0
rm -rf ./Mutation_Testing/executables_mt/* 
while [ $i -lt $provided ]
do


    rm -rf *.gc* 
    rm -rf coverage_*.*
    g++ -std=c++14 -fprofile-arcs -ftest-coverage -o ./Mutation_Testing/executables_mt/SetCover_Mutation_Exec_$i ./Mutation_Testing/mutations_CodeOnly/SetCover_CodeOnly.mutant.$i.c ./SetCover_Mutation_TestSuite/SetCover_Mutation_MetamorphicPassedTests.cpp $(pkg-config --cflags --libs gtest) -pthread

    "./Mutation_Testing/executables_mt/SetCover_Mutation_Exec_$i" &
    if [ -f "./Mutation_Testing/executables_mt/SetCover_Mutation_Exec_$i" ]; then

        pid=$!
        sleep 10
        if ps -p $pid > /dev/null; then
            echo "Timeout reached"
            echo "Mutation $i is killed\n"
            kill -9 $pid
        else
            "./Mutation_Testing/executables_mt/SetCover_Mutation_Exec_$i" > /dev/null 2>&1
            if [ $? -eq 0 ]; then
                echo "Mutation $i is killed\n"
            else
                echo "Mutation $i is survived\n"
                total_survived=$(($total_survived+1))
            fi
            "./Mutation_Testing/executables_mt/SetCover_Mutation_Exec_$i" > "./Mutation_Testing/outputs_mt/Output_Mutation_$i.txt"
            valid_mutants=$(($valid_mutants+1))
        fi

        #rm -rf ./SetCover_Mutation_Exec*
        rm -rf ./*.gc*

    fi

    i=$(($i+1))
    echo "i is printed here : $i, valid mutant : $valid_mutants"

done
left=$((valid_mutants-$total_survived))
ratio=$(echo "scale=2; $left / $valid_mutants" | bc)
printf "Total $valid_mutants valid mutants were created for the project\n"
printf "\e[32mTotal $left Mutations killed\e\n[0m"
printf "\e[31mTotal $total_survived Mutation survived out of $valid_mutants\n\e[0m"
printf "\e[32mMutation Killed rate is just $ratio in the program\n\e[0m"