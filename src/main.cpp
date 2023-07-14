
#include <exception>
#include <iostream>
#include <array>
#include <iomanip>
#include "operations.h"
using std::cout;
using std::cin;
using std::array;
using std::setfill;
using std::right;
using std::setw;

long double accumulator = 0; // our register for holding values
array<double, MEMORY_SPACE> memory; // memory of our Simpletron computer
int instructionCounter = 0; // tracks current location in memory

int main() {

    cout << "*** Welcome to Simpletron! ***\n";
    cout << "\n*** Please enter your program one instruction ***\n";
    cout << "*** (or data word) at a time. I will type the ***\n";
    cout << "*** location number and a question mark (?).  ***\n";
    cout << "*** You then type the word for that location. ***\n";
    cout << "*** Type the sentinel -99999 to stop entering ***\n";
    cout << "*** your program. ***\n\n";
    
    int memSlot = 0; // current slot to fill in memory
    int instruction = 0;

    // prompt user for instructions to run as a program
    while (memSlot < 100) {
        cout << right << setw(2) << setfill('0') << memSlot;
        cout << " ? ";
        cin >> instruction;

        if (instruction == -99999 || instruction < 0) {
            break;
        }

        memory[memSlot] = instruction;
        memSlot++;
    }

    cout << "\n*** Program loading completed ***\n*** Program execution begins  ***\n\n";


    int operationCode; // holds the operation code
    int operand; // the operand location in memory
    int instructionRegister; // holds instruction, cast from double to int

    while (true) {
        instructionRegister = static_cast<int>(memory[instructionCounter]); 
        operationCode = instructionRegister / 100; // fetch operation code part of instruction
        operand = instructionRegister % 100; // fetch location of operand part of instruction

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
                load(memory, operand, accumulator);
                instructionCounter++;
                break;
            case 21:
                store(memory, operand, accumulator);
                instructionCounter++;
                break;
            case 30:
                add(memory, operand, accumulator);
                instructionCounter++;
                break;
            case 31:
                subtract(memory, operand, accumulator);
                instructionCounter++;
                break;
            case 32:
                try {
                    divide(memory, operand, accumulator);
                } catch (std::exception e) {
                    cout << "*** Attempt to divide by zero ***\n*** Simpletron execution abnormally terminated ***\n";
                    halt(memory, accumulator, instructionCounter, instructionRegister, operationCode, operand);
                }
                instructionCounter++;
                break;
            case 33:
                multiply(memory, operand, accumulator);
                instructionCounter++;
                break;
            case 40:
                branch(instructionCounter, operand);
                break;
            case 41:
                branchNeg(instructionCounter, accumulator, operand);
                break;
            case 42:
                branchZero(instructionCounter, accumulator, operand);
                break;
            case 43:
                halt(memory, accumulator, instructionCounter, instructionRegister, operationCode, operand);
            default:
                cout << "Error: Invalid operation code input!\n";
                halt(memory, accumulator, instructionCounter, instructionRegister, operationCode, operand);
                exit(1);
        }
        if (accumulator > 9999 || accumulator < -9999) {
            cout << "*** Accumulator Overflow. Terminating Program. ***\n";
            halt(memory, accumulator, instructionCounter, instructionRegister, operationCode, operand);
            break;
        }
    } 
}
