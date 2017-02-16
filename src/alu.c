/**
 * @file alu.c
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-10
 * @brief Detailing ALU arithmetic operations.
 */

#include "alu.h"

void alu_compute(uint8_t opcode, uint8_t opA, uint8_t opB)
{
	switch(opcode) {
		case ADD:
			ac = opA + opB;
			break;
		case SUB:
			ac = opA - opB;
			break;
		case AND:
			ac = opA & opB;
			break;
		case OR:
			ac = opA | opB;
			break;
		case NOT:
			ac = ~opA;
			break;
		case XOR:
			ac = opA ^ opB;
			break;
		case ROTR:
			ac = (opA >> opB) | (opA << (sizeof(opA)-opB));
			break;
		case ROTL:
			ac = (opA << opB) | (opA >> (sizeof(opA)-opB));
			break;
	}
}

void ac_to_bus(void)
{
	bus.data = ac;
}
