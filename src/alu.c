/**
    \file alu.c
    \author Rhys Thomas (rt8g15@soton.ac.uk)
    \date 2017-02-10
    \brief Detailing ALU arithmetic operations.
*/

#include "alu.h"

/**
    \brief Sets accumulator to result of ALU operation.

    Runs ALU computation on input to ALU and accumulator based on the opcode
    provided and writes the result back to the accumulator.
 */
void alu_compute()
{
    switch(alu_task) {
        case ADD:
            opcode_print = "ADD   ";
            regs.ac += alu_input;
            break;
        case SUB:
            opcode_print = "SUB   ";
            regs.ac -= alu_input;
            break;
        case AND:
            opcode_print = "AND   ";
            regs.ac &= alu_input;
            break;
        case OR:
            opcode_print = "OR    ";
            regs.ac |= alu_input;
            break;
        case NOT:
            opcode_print = "NOT   ";
            regs.ac = ~alu_input;
            break;
        case XOR:
            opcode_print = "XOR   ";
            regs.ac ^= alu_input;
            break;
        case MUL:
            opcode_print = "MUL   ";
            regs.ac *= alu_input;
            break;
        case DIV:
            opcode_print = "DIV   ";
            regs.ac /= alu_input;
            break;
    }
}
