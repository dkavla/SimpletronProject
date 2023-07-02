
#include <iostream>
#include <array>
#include "operations.h"
using std::cout;
using std::array;

long double accumulator = 0; // our register for holding values
array<double, MEMORY_SPACE> memory; // memory of our Simpletron computer
int instructionCounter = 0; // tracks current location in memory

int main() {

    // memory[0] = 1008;
    // memory[1] = 2008;
    // memory[2] = 4106;
    // memory[3] = 3009;
    // memory[4] = 2109;
    // memory[5] = 4000;
    // memory[6] = 1109;
    // memory[7] = 4300;

    memory[14] = 7;
    memory[15] = 7;
    memory[16] = 1;
    memory[17] = 0;
    memory[18] = 0;

    memory[0] = 1019;
    memory[1] = 2019;
    memory[2] = 3017;
    memory[3] = 2117;
    memory[4] = 2014;
    memory[5] = 3116;
    memory[6] = 4209;
    memory[7] = 2114;
    memory[8] = 4000;
    memory[9] = 2017;
    memory[10] = 3215;
    memory[11] = 2118;
    memory[12] = 1118;
    memory[13] = 4300;
    

    int operationCode; // holds the operation code
    int operand; // the operand location in memory
    int instructionRegister; // holds instruction, cast from double to int

    while (true) {
        instructionRegister = static_cast<int>(memory[instructionCounter]); 
        operationCode = instructionRegister / 100; // fetch operation code part of instruction
        operand = instructionRegister % 100; // fetch location of operand part of instruction

        cout << "Current Operation Code = " << operationCode << "\n";
        // evaluate the operation code
        switch (operationCode) {
            
            case 10:
                read(memory, operand);
                cout << "Memory[" << operand << "] = " << memory[operand] << '\n';
                instructionCounter++;
                break;
            case 11:
                write(memory, operand);
                instructionCounter++;
                break;
            case 20:
                cout << "Accumulator (Before load): " << accumulator << '\n';
                load(memory, operand, accumulator);
                cout << "Accumulator (After load): " << accumulator << '\n';
                instructionCounter++;
                break;
            case 21:
                cout << "Accumulator (Before store): " << accumulator << '\n';
                store(memory, operand, accumulator);
                cout << "Accumulator (After store): " << accumulator << '\n';
                instructionCounter++;
                break;
            case 30:
                cout << "Accumulator (Before add): " << accumulator << '\n';
                add(memory, operand, accumulator);
                cout << "Accumulator (After add): " << accumulator << '\n';
                instructionCounter++;
                break;
            case 31:
                cout << "Accumulator (Before subtract): " << accumulator << '\n';
                subtract(memory, operand, accumulator);
                cout << "Accumulator (After subtract): " << accumulator << '\n';
                instructionCounter++;
                break;
            case 32:
                cout << "Accumulator (Before divide): " << accumulator << '\n';
                divide(memory, operand, accumulator);
                cout << "Accumulator (After divide): " << accumulator << '\n';
                instructionCounter++;
                break;
            case 33:
                cout << "Accumulator (Before multiply): " << accumulator << '\n';
                multiply(memory, operand, accumulator);
                cout << "Accumulator (After multiply): " << accumulator << '\n';
                instructionCounter++;
                break;
            case 40:
                cout << "Location (Before branch): " << instructionCounter << '\n';
                branch(instructionCounter, operand);
                cout << "Location (After branch): " << instructionCounter << '\n';
                break;
            case 41:
                cout << "Location (Before branchNeg): " << instructionCounter << '\n';
                branchNeg(instructionCounter, accumulator, operand);
                cout << "Location (After branchNeg): " << instructionCounter << '\n';
                break;
            case 42:
                cout << "Location (Before branchZero): " << instructionCounter << '\n';
                branchZero(instructionCounter, accumulator, operand);
                cout << "Location (After branchZero): " << instructionCounter << '\n';
                break;
            case 43:
                halt(memory, accumulator, instructionCounter, instructionRegister, operationCode, operand);
            default:
                cout << "Error: Invalid operation code input!\n";
                exit(1);
        }
        cout << "End of Operation Code " << operationCode << "\n\n";
    } 
}
