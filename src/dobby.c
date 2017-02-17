/**
 * @file dobby.c
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-10
 * @brief Dobby is a free emulator. Master gave Dobby his own architecture.
 */

#include <stdio.h>
#include <stdint.h>
#include <ncurses.h>

#include "alu.h"
#include "decoder.h"
#include "global.h"
#include "memory.h"
#include "opcodes.h"
#include "registers.h"

int clock = 0;

void print_regs(void)
{
	for(int y=1; y<8; y++) {
		if(y%2) {
			mvprintw(y, 30, "+----------+");
		} else {
			switch(y) {
				case 2:
					mvprintw(y, 27, "pc |  0x%04x  |", regs.pc);
					break;
				case 4:
					mvprintw(y, 27, "ir |  0x%04x  |", regs.ir);
					break;
				case 6:
					mvprintw(y, 27, "ac |  0x%04x  |", regs.ac);
					break;
			}
		}
	}
}

/**
 * @brief Prints debug info such as register values, instructions to execute etc.
 */
void print_debug(void)
{
	// current clock ticks
	attron(A_STANDOUT);
	mvprintw(0, 0, "Clock: %d\n",clock++);
	attroff(A_STANDOUT);

	// opcode
	mvprintw(1, 0, "Opcode");
	// current state
	mvprintw(3, 0, "States");
	mvprintw(3, 8, "pres:\t0x%04x", present_s);
	mvprintw(4, 8, "next:\t0x%04x", next_s);
	// bus
	mvprintw(6, 0, "Bus");
	mvprintw(6, 8, "addr:\t0x%04x", bus.addr);
	mvprintw(7, 8, "data:\t0x%04x", bus.data);
	// alu
	mvprintw(9, 0, "ALU");
	mvprintw(9, 8, "opA:\t0x%04x", alu_opA);
	mvprintw(10, 8, "opB:\t0x%04x", alu_opB);
	mvprintw(11, 8, "task:\t0x%04x", alu_task);
	// regs
	print_regs();
	// memory
	mvprintw(13, 0, "memory[0x%04x]: 0x%04x\n", bus.addr, memory[bus.addr]);
}

/**
 * @brief Main function. Emulates architecture.
 */
int main(void)
{
	initscr();

	// initialise next state to fetch
	next_s = FETCH;

	for(;;) {
		print_debug();
		// update when enter key has been pressed
		getch();
	}
	endwin();

	return 0;
}
