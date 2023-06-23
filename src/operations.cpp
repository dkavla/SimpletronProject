
#include "operations.h"
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <iostream>
#include <array>
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
        throw std::runtime_error("Error: division by zero not is undefined.");
    }

    accum /= mem[loc]; // divide accumulator by the value at loc in memory
    return;
}

void multiply(array<double, MEMORY_SPACE>& mem, int &loc, long double&accum) {
    accum *= mem[loc]; // accumulator is multiplied by the value at loc in memory
    return;
}

void branch(int& loc, int& newPos) {
    try {
        loc = newPos;
    } catch (std::out_of_range &outRng) {
        throw std::out_of_range("Error: New position out of range.");
    }
}

void branchNeg(int &loc, long double& accum, int &newPos) {
    try {
        if (accum < 0) {
            loc = newPos;
        } else {
            loc++;
        }
        return;
    } catch (std::out_of_range &outRng) {
        throw outRng.what();
    }
}

void branchZero(int &loc, long double& accum, int &newPos) {
    try {
        if (accum == 0) {
            loc = newPos;
        } else {
            loc++;
        }
        return;
    } catch (std::out_of_range &outRng) {
        throw outRng.what();
    }
}

void halt(long double& accum, int& inCtr, int& intReg, int& opCode, int& operand) {
    cout << "*** Simpletron execution terminated ***\n";

    cout << "REGISTERS:\n";
    
    cout << left << "accumulator          " << right << "+" << setw(4) << setfill('0') << accum << '\n';
    cout << left << "instructionCounter      " << right << setw(2) << setfill('0') << inCtr << '\n';
    cout << left << "instructionRegister  " << right << "+" << setw(4) << setfill('0') << intReg << '\n';
    cout << left << "operationCode           " << right << setw(2) << setfill('0') << opCode << '\n';
    cout << left << "operand                 " << right << setw(2) << setfill('0') << operand << '\n';

    cout << "\nMEMORY:\n";

    exit(0);
}