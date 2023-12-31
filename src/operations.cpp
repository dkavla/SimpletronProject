
#include "operations.h"
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <iostream>
#include <array>
#include <cmath>
using std::cout;
using std::cin;
using std::setw;
using std::setfill;
using std::left;
using std::right;
using std::array;

void read(array<double, MEMORY_SPACE>& mem, int &loc) {
    cout << "Enter value: ";
    cin >> mem[loc]; // read to location loc in memory
    return;
}

void write(array<double, MEMORY_SPACE>& mem, int& loc) {
    cout << mem[loc] << '\n'; // output the value stored at loc in memory
    return;
}

void load(array<double, MEMORY_SPACE>& mem, int& loc, long double& accum) {
    accum = mem[loc]; // load the value located at loc in memory to accumulator
    return;
}

void store(array<double, MEMORY_SPACE>& mem, int &loc, long double& accum) {
    mem[loc] = accum; // store current value of accumulator in location loc in memory
    accum = 0; // set the current accumulator to be zero after storing
    return;
}

void add(array<double, MEMORY_SPACE>& mem, int &loc, long double& accum) {
    accum += mem[loc]; // add value stored at loc in memory to accumulator
    return;
}

void subtract(array<double, MEMORY_SPACE>& mem, int &loc, long double& accum) {
    accum -= mem[loc]; // subtract value from loc in memory from accumulator
    return;
}

void divide(array<double, MEMORY_SPACE>& mem, int &loc, long double& accum) {
    // division by zero results in error; value must be greater than or less
    // than zero in order to get a defined result
    if (mem[loc] == 0) {
        throw std::runtime_error("Error: division by zero is undefined.");
    }

    accum /= mem[loc]; // divide accumulator by the value at loc in memory
    return;
}

void multiply(array<double, MEMORY_SPACE>& mem, int &loc, long double&accum) {
    accum *= mem[loc]; // accumulator is multiplied by the value at loc in memory
    return;
}

void branch(int& loc, int& newPos) {
    if (newPos >= MEMORY_SPACE) {
        throw std::out_of_range("Error: New position out of range.\n");
    }
    
    loc = newPos;
}

void branchNeg(int &loc, long double& accum, int &newPos) {
    
    if (newPos >= MEMORY_SPACE) {
        throw std::out_of_range("Error: New position out of range.\n");
    }

    if (accum < 0) {
        loc = newPos;
    } else {
        loc++;
    }
    return;
}

void branchZero(int &loc, long double& accum, int &newPos) {
    
    if (newPos >= MEMORY_SPACE) {
        throw std::out_of_range("Error: New position out of range.\n");
    }
    
    
    if (accum == 0) {
        loc = newPos;
    } else {
        loc++;
    }
    return;
    
}

void halt(array<double, MEMORY_SPACE>& mem, long double& accum, int& inCtr, int& intReg, int& opCode, int& operand) {
    cout << "\n\n*** Simpletron execution terminated ***\n";

    cout << "REGISTERS:\n";
    
    cout << left << "accumulator          " << right << std::showpos << setw(5) << setfill('0') << std::internal << accum << '\n';
    cout << std::noshowpos;
    cout << left << "instructionCounter      " << right << setw(2) << setfill('0') << inCtr << '\n';
    cout << left << "instructionRegister  " << right << std::showpos << setw(5) << setfill('0') << std::internal << intReg << '\n';
    cout << std::noshowpos;
    cout << left << "operationCode           " << right << setw(2) << setfill('0') << opCode << '\n';
    cout << left << "operand                 " << right << setw(2) << setfill('0') << operand << '\n';

    // output the header section of memory
    cout << "\nMEMORY:\n";
    cout << "  ";
    for (int i = 0; i < 10; ++i) {
        cout << right << setw(6) << setfill(' ') << i;
    }
    cout << '\n';
    
    // output the memory slots with their current values (instructions and variables)
    int memoryPos = 0;
    for (int i = 0; i < 100; i+=10) {
        cout << setw(2) << setfill(' ') << i << " ";
        for (int j = 0; j < 10; ++j) {
            cout << right << std::showpos << setw(5) << setfill('0') << std::internal << std::round(mem[memoryPos]) << " ";
            memoryPos++;
        }
        cout << std::noshowpos;
        cout << "\n";
    }
    

    exit(0);
}