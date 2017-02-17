/**
 * @file dobby.c
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-10
 * @brief Dobby is a free emulator. Master gave Dobby his own architecture.
 */

#include <stdio.h>
#include <stdint.h>
#include "alu.h"
#include "decoder.h"
#include "global.h"
#include "memory.h"
#include "opcodes.h"
#include "registers.h"

#define RESET "\033[0m"
#define BOLD  "\033[1m"

/**
 * @brief Prints debug info such as register values, instructions to execute etc.
 */
void print_debug(void)
{
	// states
	printf("\t%sStates%s\n", BOLD, RESET);
	printf("\tpres: 0x%04x, next: 0x%04x\n", present_s, next_s);
	// bus
	printf("\t%sBus%s\n", BOLD, RESET);
	printf("\taddr: 0x%04x, data: 0x%04x\n", bus.addr, bus.data);
	// alu
	printf("\t%sALU%s\n", BOLD, RESET);
	printf("\topA: 0x%04x, opB: 0x%04x, task: 0x%04x\n", alu_opA, alu_opB, alu_task);
	// registers
	printf("\t%sRegisters%s\n", BOLD, RESET);
	printf("\tpc: 0x%04x, ir: 0x%04x, ac: 0x%04x\n", regs.pc, regs.ir, regs.ac);
	// memory
	printf("\t%sMemory%s\n", BOLD, RESET);
	printf("\tmemory[0x%04x]: 0x%04x\n", bus.addr, memory[bus.addr]);
}

/**
 * @brief Main function. Emulates architecture.
 */
int main(void)
{
	int clock = 0;

	// initialise next state to fetch
	next_s = FETCH;

	for(;;) {
		clock++;
		printf("clock: %d\n",clock);
		print_debug();
		// update when enter key has been pressed
		getchar();
	}
	return 0;
}
