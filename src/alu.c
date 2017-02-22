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
			regs.ac = alu_input + regs.ac;
			break;
		case SUB:
			regs.ac = alu_input - regs.ac;
			break;
		case AND:
			regs.ac = alu_input & regs.ac;
			break;
		case OR:
			regs.ac = alu_input | regs.ac;
			break;
		case NOT:
			regs.ac = ~alu_input;
			break;
		case XOR:
			regs.ac = alu_input ^ regs.ac;
			break;
		case ROTR:
			regs.ac = (alu_input >> regs.ac) | (alu_input << (sizeof(alu_input)-regs.ac));
			break;
		case ROTL:
			regs.ac = (alu_input << regs.ac) | (alu_input >> (sizeof(alu_input)-regs.ac));
			break;
	}
}
