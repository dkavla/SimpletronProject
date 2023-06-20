#pragma once

#include <iostream>
#include <array>
using std::array;
using std::cout;

const size_t MEMORY_SPACE = 100; // space in memory; 100 words

/* Operations for running in Simpletron Programming Language (SML) */

/*  Input/Output Operations */ 
//  read() => reads a word from keyboard into passed in location 
//  in memory to store  
void read(array<int, MEMORY_SPACE>, int loc);

//  write() => writes the word location, loc, in memory to the screen
void write(array<int, MEMORY_SPACE>, int loc);

/*  Load/Store Operations   */
//  load() => load a word from location in memory into accumulator
void load(array<int, MEMORY_SPACE>, int loc);

// store() => stores a word from the accumulator into a specific location in memory
void store(array<int, MEMORY_SPACE>, int loc);