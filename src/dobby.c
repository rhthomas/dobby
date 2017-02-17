/**
 * @file dobby.c
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-10
 * @brief Dobby is a free emulator. Master gave Dobby his own architecture.
 */

#include "dobby.h"

void print_regs(void)
{
	for(int y=2; y<9; y++) {
		if(!(y%2)) {
			mvprintw(y, 30, "+----------+");
		} else {
			switch(y) {
				case 3:
					mvprintw(y, 27, "pc |  0x%04x  |", regs.pc);
					break;
				case 5:
					mvprintw(y, 27, "ir |  0x%04x  |", regs.ir);
					break;
				case 7:
					mvprintw(y, 27, "ac |  0x%04x  |", regs.ac);
					break;
			}
		}
	}
}

void get_state(void)
{
	switch(present_s) {
		case 0000: mvprintw(2, 8, "pres:\tDECODE  "); break;
		case 0001: mvprintw(2, 8, "pres:\tFETCH   "); break;
		case 0002: mvprintw(2, 8, "pres:\tINC_PC  "); break;
		case 0003: mvprintw(2, 8, "pres:\tALU_COMP"); break;
	}
	switch(next_s) {
		case 0000: mvprintw(3, 8, "next:\tDECODE  "); break;
		case 0001: mvprintw(3, 8, "next:\tFETCH   "); break;
		case 0002: mvprintw(3, 8, "next:\tINC_PC  "); break;
		case 0003: mvprintw(3, 8, "next:\tALU_COMP"); break;
	}
}

void get_task(void)
{
	switch(alu_task) {
		case 0000: mvprintw(10, 8, "task:\tADD "); break;
		case 0001: mvprintw(10, 8, "task:\tSUB "); break;
		case 0002: mvprintw(10, 8, "task:\tAND "); break;
		case 0003: mvprintw(10, 8, "task:\tOR  "); break;
		case 0004: mvprintw(10, 8, "task:\tNOT "); break;
		case 0005: mvprintw(10, 8, "task:\tXOR "); break;
		case 0006: mvprintw(10, 8, "task:\tROTR"); break;
		case 0007: mvprintw(10, 8, "task:\tROTL"); break;
	}
}

void print_debug(void)
{
	// current clock ticks
	attron(A_STANDOUT);
	mvprintw(0, 0, "Clock: %d\n",clock++);
	attroff(A_STANDOUT);

	// current state
	mvprintw(2, 0, "States");
	get_state();
	// bus
	mvprintw(5, 0, "Bus");
	mvprintw(5, 8, "addr:\t0x%04x", bus.addr);
	mvprintw(6, 8, "data:\t0x%04x", bus.data);
	// alu
	mvprintw(8, 0, "ALU");
	mvprintw(8, 8, "opA:\t0x%04x", alu_opA);
	mvprintw(9, 8, "opB:\t0x%04x", alu_opB);
	get_task();
	// regs
	print_regs();
	// memory
	mvprintw(12, 0, "Memory");
	mvprintw(12, 8, "addr:\t0x%04x", bus.addr);
	mvprintw(13, 8, "data:\t0x%04x", memory[bus.addr]);
}

int main(void)
{
	initscr();

	char exit;

	// initialise next state to fetch
	next_s = FETCH;

	// add 1 and 1
	memory[0]=0x0041;

	while(exit != 'q') {
		print_debug();
		cycle();
		// update when enter key has been pressed
		// exit when q is pressed
		exit = getch();
	}
	endwin();

	return 0;
}
