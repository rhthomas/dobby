/**
 * @file decoder.c
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-10
 * @brief Instruction decoder.
 *
 * Instructions are stored in the instruction register, ir. Top 4 bits
 * are opcodes, middle 6 are operand A and lower 6 bits are operand B. If it
 * an address is required then that is stored in addr which consists of all
 * the bits from the ir other than the opcodes.
 */

#include "decoder.h"

void decode(uint16_t ir) {
	// opcode is the uppder 4 bits, 0b1111.0000.0000.0000
	uint8_t opcode = (ir & 0xF000) >> 12;
	// operand a is the middle 6 bits, 0b0000.1111.1100.0000
	uint8_t a = (ir & 0x0FC0) >> 6;
	// operand b is the lower 6 bits, 0b0000.0000.0011.1111
	uint8_t b = ir & 0x003F;
	// if an address is the only parameter, take all bits except opcode
	uint16_t addr = ir & 0x0FFF;

	switch(opcode) {
		case ADD:
		case SUB:
		case AND:
		case OR:
		case NOT:
		case XOR:
		case ROTR:
		case ROTL:
			/* all handled by alu */
			alu_compute(opcode, a, b);
			/* next operation is WRTE */
			break;
		case LOAD:
			/* load data from rom[addr] to data bus */
			read_rom(addr);
			break;
		case WRTE:
			/* write data bus to ram[addr] */
			write_ram(addr);
			break;
		case JUMP:
			/* jump to address in ROM */
			pc = addr;
			break;
	}
}
