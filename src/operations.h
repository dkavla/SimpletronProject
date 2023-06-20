#pragma once

#include <iostream>
#include <array>
using std::array;

const size_t MEMORY_SPACE = 100; // space in memory; 100 words available

/* Operations for running in Simpletron Programming Language (SML) */

/*  Input/Output Operations */ 
//  Code = 10
//  read() => reads a word from keyboard into passed in location 
//  in memory to store  
void read(array<int, MEMORY_SPACE>, int& loc);

//  Code = 11
//  write() => writes the word location, loc, in memory to the screen
void write(array<int, MEMORY_SPACE>, int& loc);



/*  Load/Store Operations   */
//  Code = 20
//  load() => load a word from location in memory into accumulator
void load(array<int, MEMORY_SPACE>, int& loc, long long int& accum);

//  Code = 21
//  store() => stores a word from the accumulator into a specific location in memory
void store(array<int, MEMORY_SPACE>, int& loc, long long int& accum);


/*  Arithmetic Operations   */
//  Code = 30
//  add() => add a word from location in memory to the word in the
//  accumulator (leaving result in accumulator)
void add(array<int, MEMORY_SPACE>, int& loc, long long int& accum);

//  Code = 31
//  subtract() => subtract a word from location in memory from the
//  word in accumulator (leaving result in accumulator)
void subtract(array<int, MEMORY_SPACE>, int& loc, long long int& accum);

//  Code = 32
//  divide() => divide a word from a location in memory into the
//  word in the accumulator (leaving result in accumulator)
void divide(array<int, MEMORY_SPACE>, int& loc, long long int& accum);

//  Code = 33
//  multiply() => multiply a word from a location in memory by the 
//  word in accumulator (leaving result in accumulator)
void multiply(array<int, MEMORY_SPACE>, int& loc, long long int& accum);



/*  Transfer-Of-Control Operations  */
//  Code = 40
//  branch() => branch to a specific location in memory
int branch(int& loc);

//  Code = 41
//  branchNeg() => branch to specific location in memory if accumulator
//  is negative
int branchNeg(int& loc, long long int& accum);

//  Code = 42
//  branchzero() => branch to specific location in memory if accumulator
//  is zero
int branchZero(int& loc, long long int& accum);

//  Code = 43
// halt() => halt the program
void halt();
