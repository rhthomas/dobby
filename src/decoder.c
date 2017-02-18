/**
 * @file decoder.c
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-10
 * @brief Instruction decoder.
 *
 * Instructions are stored in the instruction register, ir. Top 4 bits
 * are opcodes, middle 6 are operand A and lower 6 bits are operand B.
 */

#include "decoder.h"

void decode(void) {
	// 0b1111.0000.0000.0000
	uint8_t opcode = (regs.ir & 0xF000) >> 12;
	// 0b0000.1111.1100.0000
	uint8_t a = (regs.ir & 0x0FC0) >> 6;
	// 0b0000.0000.0011.1111
	uint8_t b = regs.ir & 0x003F;
	// 0b0000.1111.1111.1111
	uint16_t c = regs.ir & 0x0FFF;

	switch(opcode) {
		case ADD:
		case SUB:
		case AND:
		case OR:
		case NOT:
		case XOR:
		case ROTR:
		case ROTL:
			// set ALU parameters
			alu_task = opcode;
			alu_opA  = memory[a];
			alu_opB  = memory[b];
			// run an ALU computation
			next_s = ALU_COMP;
			break;
		case LOAD:
			// DO THIS!!!!!
			// increment program counter
			next_s = INC_PC;
			break;
		case WRTE:
			// write ac to address in memory
			memory[c] = regs.ac;
			// increment program counter
			next_s = INC_PC;
			break;
		case JUMP:
			// jump to address in ROM
			regs.pc = c;
			// get next instruction
			next_s = FETCH;
			break;
	}
}

void cycle(void)
{
	// update present state
	present_s = next_s;
	switch(present_s) {
		case DECODE:
			// decode instruction register
			decode();
			// next_s is defined inside decode case statements
			break;
		case FETCH:
			// get next instruction
			bus.addr = regs.pc;
			// read data in memory at bus.addr to bus.data
			mem_read();
			// set instruction register to value of data bus
			regs.ir = bus.data;
			// now decode fetched message
			next_s = DECODE;
			break;
		case INC_PC:
			// increment the program counter
			regs.pc++;
			// fetch next instruction
			next_s = FETCH;
			break;
		case ALU_COMP:
			// run ALU computation
			alu_compute();
			next_s = INC_PC;
			break;
	}
}
