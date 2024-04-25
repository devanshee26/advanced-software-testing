
# Category Partition and Metamorphic Testing on a Set Cover and Multiple Knapsack Solution
**Developer and Author** - Devanshee Kalpeshkumar Vankani\
**StudentID** : 101290994\
**Course** : Software Engineering Project SYSC5900\
**Guided by** : Dr. Yvan Labiche

This is a term project for testing of SetCover and MultipleKnapsack problems. This project has two folders indicating "Set Cover" and "Multiple Knapsack".

# SetCover
It includes the implementation of SetCover in SetCover.c and SetCover.h files. The project uses the Google Test (gtest) framework for testing and consists of three types of testing techniques. Gtest is used as a testing framework with signal programming to catch the segmentation fault and abrupt program crashed as our failure case.

## Testing Techniques
These are the Testing techniques covered during the work of project development.
* Category Partitioning: BaseBlock Criteria, EachBlock Criteria
* Metamorphic Testing
* Mutatation Testing

## Project Structure

### Source code, Testing Source Code, and Executables
Given structure illustrates the hierarchy for the Source code for the SetCover problem, TestSuite test files and their Executables. 

SetCover_CP_Criteria_TestSuite folder has the test suites with error blocks and without error blocks test cases for Base block and Each block. It also has the files ending with Combined. Which is having all the test case with error blocks and without error blocks to calculate the code coverage for the entire either Each Block or Base Block type of testing in CP.

SetCover_MT_TestSuite folder has one test suite per metamorphic relation.

SetCover_Mutation_TestSuite folder has 3 test suites, each having all passed test cases for the Base Block, Each Block and Metamorphic relations.

### Hierarchy

```
root\Set Cover
|____ SetCover.c
|____ SetCover.h
|____ SetCover_CP_TestSuite
      |____ SetCover_CP_BaseBlock_Combined.cpp
      |____ SetCover_CP_EachBlock_Combined.cpp (Test suite without error blocks)
      |____ SetCover_CP_BaseBlock.cpp (Test suite without error blocks)
      |____ SetCover_CP_BaseBlock_ErrorBlocks.cpp
      |____ SetCover_CP_EachBlock.cpp (Test suite without error blocks)
      |____ SetCover_CP_EachBlock_ErrorBlocks.cpp
|____ SetCover_MT_TestSuite
      |____ SetCover_MT_Relation1.cpp
      |____ SetCover_MT_Relation2.cpp
      |____ SetCover_MT_Relation3.cpp
      |____ SetCover_MT_Relation4.cpp
|____ SetCover_Mutation_TestSuite
      |____ SetCover_Mutation_BaseBlockPassedTests.cpp
      |____ SetCover_Mutation_EachBlockPassedTests.cpp
      |____ SetCover_Mutation_MetamorphicPassedTests.cpp
      |____ SetCover.c
      |____ SetCover_CodeOnly.c (code without comments)
      |____ SetCover.h
```

### Testcase input and expected output files
Given structure illustrates the hierarchy for the Test Cases designed for each type of testing techniques for input and exepected_output folder. Where tests/ folder contains the test_X.txt files containing the input and expected_outputs/ folder contains the output_X.txt containing the expected output program should give.

#### Input files
In the tests/ folder, There are 4 folders named, CP_TestsWithErrorBlocks, CP_TestsWithoutErrorBlocks, MetamorphicTesting, MutationTesitng. Folders starting with CP are containing CP_BaseBlock and CP_EachBlock as the subfolders, which has all the input file for the specific test case. MetamorphicTesting folder has Relation1 to Relation4 folders and which has all the input file for the specific test case. Similarly, MutationTesitng folder has BaseBlockAllPassed, EachBlockAllPassed and MetamorphicAllPassed as subfolders and they've the input file for the test cases.

#### Expected output files
expected_outputs folder has the same hierarchy mentioned above but with the expected output file for the test cases.

#### Hierarchy
```
root/Set Cover/tests/
      |____ CP_TestsWithErrorBlocks
            |____ CP_BaseBlock            
                  |____ input_X.txt (input text file)
            |____ CP_EachBlock            
                  |____ input_X.txt (input text file)
      |____ CP_TestsWithoutErrorBlocks
            |____ CP_BaseBlock            
                  |____ input_X.txt (input text file)
            |____ CP_EachBlock            
                  |____ input_X.txt (input text file)
      |____ MetamorphicTesting
            |____ Relation1
                  |____ input_X.txt (input text file)
            |____ Relation2
                  |____ input_X.txt (input text file)
            |____ Relation3            
                  |____ input_X.txt (input text file)
            |____ Relation4          
                  |____ input_X.txt (input text file)
      |____ MutationTesitng
            |____ BaseBlockAllPassed
                  |____ input_X.txt (input text file)
            |____ EachBlockAllPassed
                  |____ input_X.txt (input text file)
            |____ MetamorphicAllPassed            
                  |____ input_X.txt (input text file)
```

### Mutation testing
This is the hierarchy for the Mutation testing setup, where Mutation_Testing/ folder contains just one folder mutations_CodeOnly and it contains all the generated mutants by the universal mutator. We'll see further how it is installed and how mutants are generated.

### Hierarchy

```
root\Set Cover\Mutation_Testing
|____ mutations_CodeOnly
      |____ SetCover_CodeOnly.mutant.X.cpp (X number mutant)
```

## Coverage Reports
Html and CSS for report of the Test suites are stored in current folder. It can be divided into two parts. 

First being, the CoverageAnalysis folder. Which has all the subfolders for the respective testing techniques (CP and MT). Each of that folder has their test critera with error and without error blocks folder associated with it. For ex. CP folder has BaseBlock_WithError folder. And each those folder has Test_X folders named in it. Which has the coverage reports for the coverage analysis for that particular test suite and test case. Similarly, MT has RelationX subfolders and it has RX_X subfolders named in it. Which has the coverage report for the specific metamorphic relation X with the corresponding test case.

Second being, all the other folders which are having coverage reports for the specific test criteria with error and without error blocks. For ex. CP_BaseBlock_ErrorBlocks_CoverageReports has the structural coverage for the BaseBlock's with error block's test suite.

```
root/Set Cover/CoverageReports/
      |____ CoverageAnalysis
            |____ CP    
                  |____ BaseBlock_WithError
                        |____ Test_X  
                              |____ coverage files
                  |____ BaseBlock_WithoutError  
                        |____ Test_X  
                              |____ coverage files
                  |____ EachBlock_WithError  
                        |____ Test_X  
                              |____ coverage files
                  |____ EachBlock_WithoutError  
                        |____ Test_X  
                              |____ coverage files
            |____ MT  
                  |____ Relation1
                        |____ RX_X  
                              |____ coverage files
                  |____ Relation2
                        |____ RX_X  
                              |____ coverage files
                  |____ Relation3
                        |____ RX_X  
                              |____ coverage files
                  |____ Relation4
                        |____ RX_X  
                              |____ coverage files
      |____ CP_BaseBlock_Combined_CoverageReport
            |____ coverage files
      |____ CP_EachBlock_Combined_CoverageReport
            |____ coverage files
      |____ CP_BaseBlock_ErrorBlocks_CoverageReport
            |____ coverage files
      |____ CP_BaseBlock_CoverageReport
            |____ coverage files
      |____ CP_EachBlock_ErrorBlocks_CoverageReport
            |____ coverage files
      |____ CP_EachBlock_CoverageReport
            |____ coverage files
      |____ MT_R1_CoverageReport
            |____ coverage files
      |____ MT_R2_CoverageReport
            |____ coverage files
      |____ MT_R3_CoverageReport
            |____ coverage files
      |____ MT_R4_CoverageReport
            |____ coverage files
```

## Installation / Setup / Run program files
- Make sure the machine has gcc/g++ installed for C/C++
- Then Inatall the gtest and gcov and gcovr tools for our project
- run following commands
   * `brew install googletest`
   * `brew install gcov`
   * `brew install gcovr`
- to install the universal-mutator for mutation testing run
   * `pip install universalmutator`

### Category Partitioning and Metamorphic Testing
   * Run the given commands from ./Set Cover folder. Generating exec Files: To generate the exec files, use the following commands: Follow the same steps for

- For Category Partitioning, replace **"Criteria"** with **BaseBlock, EachBlock, BaseBlock_Combined, EachBlock_Combined, BaseBlock_ErrorBlocks, EachBlock_ErrorBlocks**

   ```bash
   rm -rf *.gc*
   g++ -std=c++14 -fprofile-arcs -ftest-coverage -o ./SetCover_CP_TestSuite/SetCover_CP_CRITERIA_Exec SetCover.c ./SetCover_CP_TestSuite/ SetCover_CP_CRITERIA.cpp  $(pkg-config --cflags --libs gtest) -pthread -lgtest  -lgtest_main -lpthread
   ./SetCover_CP_TestSuite/SetCover_CP_CRITERIA_Exec
   gcov SetCover.c
   gcovr -r . --html --html-details -o ./CoverageReports/CP_CRITERIA_CoverageReport/coverage_report.html
   ```

- For Metamorphic testing, replace **"X"** with **1,2,3,4**

   ```bash
   rm -rf *.gc*
   g++ -std=c++14 -fprofile-arcs -ftest-coverage -o ./SetCover_MT_TestSuite/SetCover_MT_RelationX_Exec SetCover.c ./SetCover_MT_TestSuite/SetCover_MT_RelationX.cpp  $(pkg-config --cflags --libs gtest) -pthread -lgtest -lgtest_main -lpthread
   ./SetCover_MT_TestSuite/SetCover_MT_RelationX_Exec
   gcov SetCover.c
   gcovr -r . --html --html-details -o ./CoverageReports/MT_RX_CoverageReport/coverage_report.html
   ```

#### Coverage Analysis
Note that coverage analysis is done by incorporating each test case one by one in the test suite and measuring the code coverage. This process will gives the change of code coverage resulted from the newly inserted test case in the file. 

Hierarchy is the same as shown in the folder structure of CoverageAnalysis in CoverageReports.

Each of the test suites are ran in the similar way described below.

- Go to the bin directory of the CoverageAnalysis
   `cd ./CoverageAnalysis/bin`
- Run the following scripts for each type of the coverage analysis. Also, note that, the coverage reports are generated in the ./CoverageReports/CoverageAnalysis folder in their respective folders
   `./BaseBlock_WithError.sh`\
   `./BaseBlock_WithoutError.sh`\
   `./EachBlock_WithError.sh`\
   `./EachBlock_WithoutError.sh`\
   `./MT_Coverage_Analysis_Script.sh`

### Mutatation testing
- Change the working directory to Mutation_Testing/mutations_CodeOnly\
   `cd ./Mutation_Testing/mutations_CodeOnly`
- run the following command to generate the mutants\
   `mutate ../../SetCover_CodeOnly.c --mutantDir .`

- Then, I've developed three shell script files, which will **automate** all the testing process.

- In the shell script, It will take each mutants from 290th to 390th mutants and it'll compile the SetCover_CodeOnly.mutant.X.c file and create a executble file. Now all the test cases will run against the mutant and if all test case SetCover_Mutation_BaseBlockPassedTests then it'll make the mutant survived. Otherwise, if one of the test case got failed then the mutant is killed. Analysis is printed for each type of testing critera after running the script.

- Run the following command to automate the Mutation Testing for Base Block Category Partition from the root folder

   `./Mutation_Testing_CP_BaseBlocks.sh`
   
   It'll print all the details of mutants survival and killing.

- Likewise it can be done for Each Block and Metamorphic testing.


# Multiple Knapsack
There is a directory named Multiple Knapsack in the source of the proejct and the main project files are in MultipleKnapsack folder. It includes the implementation of Multiple Knapsack in MultipleKnapsack.java, Knapsack.java and KnapsackItem.java files under src directoy. The project uses the JUnit framework for testing, maven for managing the dependenies. JUnit is used as a testing framework with pi-test framework to test the code for mutation testing.

## Setting up and Running the Project

### MultipleKnapsack directory Contents
- pom.xml - The Maven configuration
- src - Directory containing the utilized Java code, including the test suites and the multiple knapsack solution implementation
- Additional files will be generated by Eclipse and Maven when running the experiments.

#### Folder structure

```
root/Multiple Knapsack/multiKnapsack/src/main/java/sysc5105/multiKnapsack\
|____ KnapsackItem.java\
|____ Main.java\
|____ Knapsack.java\
|____ MultipleKnapsack.java\
```

```
root/Multiple Knapsack/multiKnapsack/src/test/java/sysc5105/multiKnapsack
|____ Helper.java
|____ CP_BaseBlock_Combined.java
|____ CP_BaseBlockWithErrorBlocks.java
|____ CP_BaseBlockWithoutErrorBlocks.java
|____ CP_EachBlockWithErrorBlocks.java
|____ CP_EachBlockWithoutErrorBlocks.java
|____ CP_EachBlock_Combined.java
|____ CP_Mutation.java
|____ MT_Mutation.java
|____ CoverageAnalysis
      |____ CP
            |____ BaseBlockWithErrorBlocks
                  |____ BaseBlockWithErrorBlocksX.java (all the test suites)
            |____ BaseBlockWithoutErrorBlocks
                  |____ BaseBlockWithoutErrorBlocksX.java (all the test suites)
            |____ EachBlockWithErrorBlocks
                  |____ EachBlockWithErrorBlocksX.java (all the test suites)
            |____ EachBlockWithoutErrorBlocks
                  |____ EachBlockWithErrorBlocksX.java (all the test suites)
      |____ MT
            |____ MetamorphicRelation1
                  |____ MetamorphicRelation1_X.java (all the test suites)
            |____ MetamorphicRelation2
                  |____ MetamorphicRelation2_X.java (all the test suites)
            |____ MetamorphicRelation3
                  |____ MetamorphicRelation3_X.java (all the test suites)
            |____ MetamorphicRelation4
                  |____ MetamorphicRelation4_X.java (all the test suites)
            |____ MetamorphicRelation5
                  |____ MetamorphicRelation5_X.java (all the test suites)
```

### Installation
For the following installation steps, the experiments were originally run in MacOS. Thus the installation steps are geared towards that OS, alternative setup may be required for other operating systems.

#### Java
This project requires Java 8 or 12.

#### Maven
This project uses Maven to run the tests. Any latest maven version is supported.

Once Maven is installed, run `mvn -v` from the terminal, and ensure that it displays the correct version of Maven, and the correct version of Java.

#### Eclipse IDE
The EclEmma plugin for Eclipse was used for code coverage analysis, thus the Eclipse IDE is required for the experiment.

EclEmma was included by default in the installation used for the experiments. To confirm this is the case, within the Eclipse IDE, select the `Help` dropdown, and select `About Eclipse IDE`. Then select `Installation Details` in the pop up.
The `Installed Software` tab will have a list of all the Eclipse components in this version. You can manually scroll through it or filter at the top for "EclEmma".

If EclEmma is not installed, it can be installed through the Eclipse Marketplace.
Within the Eclipse IDE, select the `Help` dropdown, and select `Eclipse Market Place...`. 
In the `Search` tab, search for "EclEmma".
Install the "EclEmma Java Code Coverage" item.

### Running the Experiments
At this point, it is important to note that there are two sets one of seven test suites(it includes one test suite ending with Mutation which is a mutation test suite, and two test suites ending with Combined which has all the test cases of BaseBlock in one file and of EachBlock in one file) and the other of six test suites (it includes one test suite ending with Mutation which is a mutation test suite and other 5 metamorphic relations test suite). The Mutation Testing tool requires all the tests to be passing. The test classes ending with Mutation are required for pi-test framework for the mutation testing. 

#### Handling of output comparison
In the directory structure, the Helper.java can be found which is responsible for gernating the expected output objects and for comparing those objects with the actual output objects.

#### Executing Tests
1. In the terminal, navigate to the directory which contains the pom.xml and src directory
2. Run `mvn test -Dtest=“sysc5105.multiKnapsack.CP_BaseBlock*” (for all base block test classes)`
3. Maven will run all of the tests (specifically, the tests in the test classes which do not contain "Mutation" in the name and of WithErroBlocks and WithoutErroBlocks), and output the results to the console
4. Similarly any regex pattern can be applied to run the specific test suites.

#### Code Coverage
1. Open Eclipse
2. Select the `File` dropdown, then select `Import...`
3. In the pop, expand the `Maven`, select `Existing Maven Projects`, and hit `Next`
4. Using the `Browse` option, select the directory which contains the previously described pom.xml and src directory (should be the same location as this README), ensure the `pom.xml` file is selected, and then hit `Finish`
5. The `multiKnapsack` project should now be listed in the Eclipse Package Explorer.
6. Expand the project, then expand the `src/test/java` entry, then expand the `sysc5105.multiKnapsack` package
7. All the test files will be listed now
8. Right click on one of the test files (The experiments described in the paper used the files not containing "Mutation" in the name)
9. Select `Coverage As...` and then select `JUnit Test`
10. A `Coverage` tab should be opened, displaying the results (statement coverage by default), which can be exploded at your leisure. The report only reports coverage on files in the `src/main/java` directory (i.e. not including coverage of the test classes), which can be viewed in this way
11. At the very top right of this `Coverage` tab, there is an arrow for a drop down
12. This drop down contains options to view different types of coverage, as well as export the results as HTML

#### Coverage Analysis
Note that coverage analysis is done by incorporating each test case one by one in the test suite and measuring the code coverage. This process will gives the change of code coverage resulted from the newly inserted test case in the file. 

As shown in the folder structure descibed above,

All the coverage analysis related files can be found in the CoverageAnalysis folder in the test folder. It has the folders respective to the Category Partition(CP) and Metamorphic Testing (MT). These folders has subfolders named EachBlockWithErrorBlocks, EachBlockWithoutErrorBlocks, BaseBlockWithErrorBlocks, BaseBlockWithoutErrorBlocks in CP and MetamorphicRelation1, MetamorphicRelation2, MetamorphicRelation3, MetamorphicRelation4 and MetamorphicRelation5 in MT folder. 

Each of the subfolders in the CP has the test suites corresponding to which new test case is added at one time. Where as, each of the subfolders in the MT has the test suites corresponding to which new test case is added at one time for that particular relation.

Each of the test suites are ran in the similar way described above.

#### Mutation Testing
Note that these experiments use the test suites ending with "Mutation".
1. In the terminal, navigate to the directory which contains pom.xml and src directory 
2. To run mutation testing on all the test suites at once, run `mvn test-compile org.pitest:pitest-maven:mutationCoverage`
3. To run mutation testing on a specific test suite, run `mvn test-compile org.pitest:pitest-maven:mutationCoverage -P <profile>` replacing '<profile\>' with one of `categoryPartition`, or `metamorphic` which corresponds to the test suite you would like to run.
4. The results will be printed to the console, and an HTML output file can be found in the `target/pit-reports` directory (the `target` directory will be created in the same directory as the pom.xml file)


### Acknowledgements
The multiple knapsack solution implementation was built by Kemal Kojic, retrieved from here: https://github.com/kemaldev/Multiple-Knapsack-Problem


### Thank You!
Author - Devanshee Kalpeshkumar Vankani