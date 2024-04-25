#!/bin/sh

provided=390

i=290
valid_mutants=0
total_survived=0
rm -f ./Mutation_Testing_CP_BaseBlocks_Survived.txt
while [ $i -ne $provided ]
do

    rm -rf *.gc* 
    rm -rf coverage_*.*
    g++ -std=c++14 -o ./SetCover_Mutation_TestSuite/SetCover_Mutation_Exec_$i ./Mutation_Testing/mutations_CodeOnly/SetCover_CodeOnly.mutant.$i.c ./SetCover_Mutation_TestSuite/SetCover_Mutation_BaseBlockPassedTests.cpp $(pkg-config --cflags --libs gtest) -pthread
       
    "./SetCover_Mutation_TestSuite/SetCover_Mutation_Exec_$i" &
    pid=$!
    if [ -f "./SetCover_Mutation_TestSuite/SetCover_Mutation_Exec_$i" ]; then
        valid_mutants=$(($valid_mutants+1))
        # pid=$!
        sleep 10
        if ps -p $pid > /dev/null; then
            echo "Timeout reached"
            echo "Mutation $i is killed\n"
            kill -9 $pid
        else
            "./SetCover_Mutation_TestSuite/SetCover_Mutation_Exec_$i" > /dev/null 2>&1
            exit_status=$?
            echo "devansheereturns $exit_status"
            if [ $exit_status -eq 0 ]; then
                echo "Mutation $i is survived" >> ./Mutation_Testing_CP_BaseBlocks_Survived.txt
                total_survived=$(($total_survived+1))
            else
                echo "Mutation $i is killed\n"
            fi
        fi

        rm -r ./SetCover_Mutation_TestSuite/SetCover_Mutation_Exec*
        rm -rf ./*.gc*

    fi

    i=$(($i+1))

done
left=$((valid_mutants-$total_survived))
ratio=$(echo "scale=2; $left / $valid_mutants" | bc)
printf "Total $valid_mutants valid mutants were created for the project\n"
printf "\e[32mTotal $left Mutations killed\e\n[0m"
printf "\e[31mTotal $total_survived Mutation survived out of $valid_mutants\n\e[0m"
printf "\e[32mMutation Killed rate is just $ratio in the program\n\e[0m"