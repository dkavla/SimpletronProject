
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
                try {
                    divide(memory, operand, accumulator);
                } catch (std::exception e) {
                    cout << "*** Attempt to divide by zero ***\n*** Simpletron execution abnormally terminated ***\n";
                    halt(memory, accumulator, instructionCounter, instructionRegister, operationCode, operand);
                }
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
