/**
 * @file decoder.c
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-10
 * @brief Instruction decoder.
 * @todo Implement simple state machine.
 *
 * Instructions are stored in the instruction register, ir. Top 4 bits
 * are opcodes, middle 6 are operand A and lower 6 bits are operand B. If it
 * an address is required then that is stored in addr which consists of all
 * the bits from the ir other than the opcodes.
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
			alu_opA  = a;
			alu_opB  = b;
			// next, run an ALU computation
			next_s = ALU_COMP;
			break;
		case LOAD:
			// load data from rom[addr] to data bus
			read_rom(c);
			// increment program counter
			next_s = INC_PC;
			break;
		case WRTE:
			// write accumulator to address c
			bus.data = regs.ac;
			next_s = INC_PC;
			break;
		case JUMP:
			// jump to address in ROM
			regs.pc = c;
			// get next instruction
			next_s = GET_INST;
			break;
	}
}

void update_cpu(void)
{
	present_s = next_s;
	switch(present_s) {
		case DECODE:
			// decode instruction register
			decode();
			// next_s are defined inside decode case statements
			break;
		case GET_INST:
			// get next instruction
			bus.addr = regs.pc;
			// read data in memory at bus.addr to bus.data
			mem_read();
			next_s = SET_INST;
			break;
		case SET_INST:
			// set instruction register to value of data bus
			regs.ir = bus.data;
			break;
		case INC_PC:
			// increment the program counter
			regs.pc++;
			next_s = GET_INST;
			break;
		case ALU_COMP:
			// run ALU computation
			/**
			 * @todo Think of a better way to do this. See lecture slides on
			 *  accumulator ISA.
			 */
			alu_compute();
			next_s = INC_PC;
			break;
	}
}
