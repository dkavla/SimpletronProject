# SimpletronProject
A project implemented in C++ in which we create our own computer called Simpletron that runs Simpletron Machine Language (SML), our made up language for this project.

## Structure of Simpletron
Our Simpletron computer will contain a accumulator--a "special register" which will hold information before it is used for calculations or other tasks. Additionally, it will have a 100 word memory. A "word" is a signed 4-digit decimal (e.g. +3364, -1293, +0007, etc.).

An instruction is the 4-digit decimal, where the first two digits are the operation code that will be executed while the last two digits are the operand--the address of the memory location containing the word to which the operation applies. Instructions are positive values, therefore, a negative instruction is considered invalid.

The first instruction is placed in location 00 of memory, and the following instructions are placed in the locations that follow, so 01, 02, and so on.

## Operation Codes

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


