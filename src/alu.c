/**
 * @file alu.c
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-10
 * @brief Detailing ALU arithmetic operations.
 */

#include "alu.h"

void alu_compute(void)
{
	switch(alu_task) {
		case ADD:
			regs.ac = alu_opA + alu_opB;
			break;
		case SUB:
			regs.ac = alu_opA - alu_opB;
			break;
		case AND:
			regs.ac = alu_opA & alu_opB;
			break;
		case OR:
			regs.ac = alu_opA | alu_opB;
			break;
		case NOT:
			regs.ac = ~alu_opA;
			break;
		case XOR:
			regs.ac = alu_opA ^ alu_opB;
			break;
		case ROTR:
			regs.ac = (alu_opA >> alu_opB) | (alu_opA << (sizeof(alu_opA)-alu_opB));
			break;
		case ROTL:
			regs.ac = (alu_opA << alu_opB) | (alu_opA >> (sizeof(alu_opA)-alu_opB));
			break;
	}
}
