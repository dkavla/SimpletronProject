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
void read(array<double, MEMORY_SPACE>& mem, int& loc);

//  Code = 11
//  write() => writes the word location, loc, in memory to the screen
void write(array<double, MEMORY_SPACE>& mem, int& loc);



/*  Load/Store Operations   */
//  Code = 20
//  load() => load a word from location in memory into accumulator
void load(array<double, MEMORY_SPACE>& mem, int& loc, long double& accum);

//  Code = 21
//  store() => stores a word from the accumulator into a specific location in memory
void store(array<double, MEMORY_SPACE>& mem, int& loc, long double& accum);


/*  Arithmetic Operations   */
//  Code = 30
//  add() => add a word from location in memory to the word in the
//  accumulator (leaving result in accumulator)
void add(array<double, MEMORY_SPACE>& mem, int& loc, long double& accum);

//  Code = 31
//  subtract() => subtract a word from location in memory from the
//  word in accumulator (leaving result in accumulator)
void subtract(array<double, MEMORY_SPACE>& mem, int& loc, long double& accum);

//  Code = 32
//  divide() => divide a word from a location in memory into the
//  word in the accumulator (leaving result in accumulator)
void divide(array<double, MEMORY_SPACE>& mem, int& loc, long double& accum);

//  Code = 33
//  multiply() => multiply a word from a location in memory by the 
//  word in accumulator (leaving result in accumulator)
void multiply(array<double, MEMORY_SPACE>& mem, int& loc, long double& accum);



/*  Transfer-Of-Control Operations  */
//  Code = 40
//  branch() => branch to a specific location in memory
void branch(int& loc, int& newPos);

//  Code = 41
//  branchNeg() => branch to specific location in memory if accumulator
//  is negative
void branchNeg(int& loc, long double& accum, int& newPos);

//  Code = 42
//  branchzero() => branch to specific location in memory if accumulator
//  is zero
void branchZero(int& loc, long double& accum, int& newPos);

//  Code = 43
// halt() => halt the program
void halt(long double& accum, int& inCtr, int& intReg, int& opCode, int& operand);
