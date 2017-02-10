/**
 * @file alu.c
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-10
 * @brief Detailing ALU arithmetic operations.
 */

#include "alu.h"

void alu_compute(void)
{
	switch(/* something */) {
		case ADD:
			/* out = aluA + aluB; */
			break;
		case SUB:
			/* out = aluA - aluB; */
			break;
		case AND:
			/* out = aluA & aluB; */
			break;
		case OR:
			/* out = aluA | aluB; */
			break;
		case NOT:
			/* out = ~aluA; */
			break;
		case XOR:
			/* out = aluA ^ aluB; */
			break;
		case ROTR:
			/* out = (aluA >> aluB) | (aluA << (sizeof(aluA)-aluB)) */
			break;
		case ROTL:
			/* out = (aluA << aluB) | (aluA >> (sizeof(aluA)-aluB)) */
			break;
	}
}
