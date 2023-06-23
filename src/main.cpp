
#include <iostream>
#include <array>
#include "operations.h"
using std::cout;
using std::array;

long double accumulator = 0; // our register for holding values
array<double, MEMORY_SPACE> memory; // memory of our Simpletron computer
int location = 0; // tracks current location in memory

int main() {
    // Sentinel-controlled loop that reads positive numbers and computes
    // and displays their sum
    // memory[0] = 1008;
    // memory[1] = 2008;
    // memory[2] = 4106;
    // memory[3] = 3009;
    // memory[4] = 2109;
    // memory[5] = 4000;
    // memory[6] = 1109;
    // memory[7] = 4300;


    // Counter controlled loop that reads positive and negative numbers
    // and then computes the average once counter equals zero
    
    memory[14] = 7; // counter variable
    memory[15] = 7; // divisor for calculating average
    memory[16] = 1; // decrementer; stays constant

    // Instructions:
    memory[0] = 1019; 
    memory[1] = 2019; 
    memory[2] = 3017;
    memory[3] = 2117;
    memory[4] = 2014;
    memory[5] = 3116;
    memory[6] = 4209; // branchZero
    memory[7] = 2114;
    memory[8] = 4000; // branch
    memory[9] = 2017;
    memory[10] = 3215;
    memory[11] = 2118;
    memory[12] = 1118;
    memory[13] = 4300;


    int operation; // holds the operation code
    int operandLoc; // the operand location in memory
    int instruction; // holds instruction, cast from double to int

    while (true) {
        instruction = static_cast<int>(memory[location]); 
        operation = (instruction % 10000 - instruction % 100) / 100; // fetch operation code part of instruction
        operandLoc = instruction % 100; // fetch location of operand part of instruction

        cout << "Current Operation Code = " << operation << "\n";
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
                break;
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
