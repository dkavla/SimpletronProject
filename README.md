# SimpletronProject
A project implemented in C++ in which we create our own computer simulator called Simpletron that runs Simpletron Machine Language (SML), our made up language for this project.

## Structure of Simpletron
Our Simpletron computer will contain a accumulator--a "special register" which will hold information before it is used for calculations or other tasks. Additionally, it will have a 100 word memory. A "word" is a signed 4-digit decimal (e.g. +3364, -1293, +0007, etc.).

An instruction is the 4-digit decimal, where the first two digits are the operation code that will be executed while the last two digits are the operand--the address of the memory location containing the word to which the operation applies. Instructions are positive values, therefore, a negative instruction is considered invalid.

The first instruction is placed in location 00 of memory, and the following instructions are placed in the locations that follow, so 01, 02, and so on.

The simulator starts by prompting the user for instructions (the program), in the SML language syntax, which are added into memory. Afterwards, the instructions are processed and run until a 43 operation code is processed. 

## Operation Codes
The following are the supported operations codes for the SML language in this project.

| Operation code  |       Meaning                                                                                                       |
|-----------------|---------------------------------------------------------------------------------------------------------------------|
| 10 (read)       | Read a word from the keyboard into a specific location in memory.                                                   |
| 11 (write)      | Write a word from a specific location in memory to the screen.                                                      |
| 20 (load)       | Load a word from a specific location in memory into the accumulator.                                                |
| 21 (store)      | Store a word from the accumulator into a specific locaiton in memory.                                               |
| 30 (add)        | Add a word from a specific location in memory to the word in the accumulator (leave result in accumulator).         |
| 31 (subtract)   | Subtract a word from a specific location in memory from the word in the accumulator (leave result in accumulator).  |
| 32 (divide)     | Divide a word from a specific location in memory into the word in the accumulator (leave the result in accumulator).|
| 33 (multiply)   | Multiply a word from a specific location in memory by the word in the accumulator (leave result in accumulator).    |
| 40 (branch)     | Branch to a specific location in memory                                                                             |
| 41 (branchneg)  | Branch to a specific location in memory if the accumulator is negative.                                             |
| 42 (branchzero) | Branch to a specific location in memory if accumulator is zero.                                                     |
| 43 (halt)       | Halt--the program has completed its task                                                                            |


# Test Programs
The following are programs in Simpletron Machine Language syntax that you can try when running the simulator.

## Program #1
This program will prompt the user to enter integers until a negative value is entered. It will compute the sum all numbers entered, with the exception of the negative integer, and displays it at the end.

        1008
        2008
        4106
        3009
        2109
        4000
        1109
        4300

## Program #2
This program will use a counter controlled loop to read seven numbers, positive and negative, and then compute their average. The result is then displayed at the end of the program's run. The first three commands are for inputting the counter variable (in this case 7), the divisor variable for calculating the average (the same as the first value), and the decrementer (the value 1 if we are decrementing by 1).

        1017 (enter 7 for this prompt)
        1018 (enter 7 here as well)
        1019 (enter 1 for this prompt)
        1022 (this is when you start entering your values)
        2022
        3020
        2120
        2017
        3119
        4212
        2117
        4003
        2020
        3218
        2121
        1121
        4300



