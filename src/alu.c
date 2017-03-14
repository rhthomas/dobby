/**
    \file alu.c
    \author Rhys Thomas (rt8g15@soton.ac.uk)
    \created 2017-02-10
    \brief Detailing ALU arithmetic operations.
*/

#include "alu.h"

void alu_compute()
{
    switch(alu_task) {
        case ADD: regs.ac += alu_input; break;
        case SUB: regs.ac -= alu_input; break;
        case AND: regs.ac &= alu_input; break;
        case OR:  regs.ac |= alu_input; break;
        case NOT: regs.ac = ~alu_input; break;
        case XOR: regs.ac ^= alu_input; break;
        case MUL: regs.ac *= alu_input; break;
        case DIV: regs.ac /= alu_input; break;
    }
}
