
#include <iostream>
#include <array>
#include "operations.h"
using std::cout;
using std::array;

long long int accumulator = 0; // our register for holding values
array<int, MEMORY_SPACE> memory; // memory of our Simpletron computer
int location = 0; // tracks current location in memory

int main() {
    // Test program 1
    // memory[0] = 1007;
    // memory[1] = 1008;
    // memory[2] = 2007;
    // memory[3] = 3008;
    // memory[4] = 2109;
    // memory[5] = 1109;
    // memory[6] = 4300;

    // Test program 2
    // memory[0] = 1009;
    // memory[1] = 1010;
    // memory[2] = 2009;
    // memory[3] = 3110;
    // memory[4] = 4107;
    // memory[5] = 1109;
    // memory[6] = 4300;
    // memory[7] = 1110;
    // memory[8] = 4300;

    int operation = 0; // holds the operation code
    int operandLoc = 0; // stores the operand location

    while (true) {
        operation = (memory[location] % 10000 - memory[location] % 100) / 100; // fetch operation code part of instruction
        operandLoc = memory[location] % 100; // fetch location of operand part of instruction

        cout << "\nCurrent Operation Code = " << operation << "\n";
        // evaluate the operation code
        switch (operation) {
            
            case 10:
                read(memory, operandLoc);
                cout << "Memory[" << operandLoc << "] = " << memory[operandLoc] << '\n';
                location++;
                break;
            case 11:
                write(memory, operandLoc);
                location++;
                break;
            case 20:
                cout << "Accumulator (Before load): " << accumulator << '\n';
                load(memory, operandLoc, accumulator);
                cout << "Accumulator (After load): " << accumulator << '\n';
                location++;
                break;
            case 21:
                cout << "Accumulator (Before store): " << accumulator << '\n';
                store(memory, operandLoc, accumulator);
                cout << "Accumulator (After store): " << accumulator << '\n';
                location++;
                break;
            case 30:
                cout << "Accumulator (Before add): " << accumulator << '\n';
                add(memory, operandLoc, accumulator);
                cout << "Accumulator (After add): " << accumulator << '\n';
                location++;
                break;
            case 31:
                cout << "Accumulator (Before subtract): " << accumulator << '\n';
                subtract(memory, operandLoc, accumulator);
                cout << "Accumulator (After subtract): " << accumulator << '\n';
                location++;
                break;
            case 32:
                cout << "Accumulator (Before divide): " << accumulator << '\n';
                divide(memory, operandLoc, accumulator);
                cout << "Accumulator (After divide): " << accumulator << '\n';
                location++;
                break;
            case 33:
                cout << "Accumulator (Before multiply): " << accumulator << '\n';
                multiply(memory, operandLoc, accumulator);
                cout << "Accumulator (After multiply): " << accumulator << '\n';
                location++;
                break;
            case 40:
                cout << "Location (Before branch): " << location << '\n';
                branch(location, operandLoc);
                cout << "Location (After branch): " << location << '\n';
                break;
            case 41:
                cout << "Location (Before branchNeg): " << location << '\n';
                branchNeg(location, accumulator, operandLoc);
                cout << "Location (After branchNeg): " << location << '\n';
                break;
            case 42:
                cout << "Location (Before branchZero): " << location << '\n';
                branchZero(location, accumulator, operandLoc);
                cout << "Location (After branchZero): " << location << '\n';
            case 43:
                cout << "Program Terminated.\n";
                halt();
            default:
                cout << "Error: Invalid operation code input!\n";
                exit(1);
        }
        cout << "End of Operation Code " << operation << "\n\n";
    } 
}
