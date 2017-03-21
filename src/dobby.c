/**
    \file dobby.c
    \author Rhys Thomas (rt8g15@soton.ac.uk)
    \date 2017-02-10
    \brief Dobby is a free emulator. Master gave Dobby his own architecture.
*/

#include "dobby.h"

int clock = 0;

void print_regs()
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

void get_state()
{
    switch(present_s) {
        case 0000: mvprintw(4, 8, "pres:\tDECODE  "); break;
        case 0001: mvprintw(4, 8, "pres:\tFETCH   "); break;
        case 0002: mvprintw(4, 8, "pres:\tINC_PC  "); break;
    }
    switch(next_s) {
        case 0000: mvprintw(5, 8, "next:\tDECODE  "); break;
        case 0001: mvprintw(5, 8, "next:\tFETCH   "); break;
        case 0002: mvprintw(5, 8, "next:\tINC_PC  "); break;
    }
}

void print_debug()
{
    // current clock ticks
    attron(A_STANDOUT);
    mvprintw(0, 0, "Clock: %d\n",clock++);
    attroff(A_STANDOUT);
    // opcode
    mvprintw(2, 0, "Opcode:");
    mvprintw(2, 8, "%s", opcode_print);
    // current state
    mvprintw(4, 0, "State");
    get_state();
    // bus
    mvprintw(7, 0, "Bus");
    mvprintw(7, 8, "addr:\t0x%04x", bus.addr);
    mvprintw(8, 8, "data:\t0x%04x", bus.data);
    // alu
    mvprintw(10, 0, "ALU");
    mvprintw(10, 8, "input:\t0x%04x", alu_input);
    // regs
    print_regs();
    // memory
    mvprintw(12, 0, "Memory");
    mvprintw(12, 8, "addr:\t0x%04x", bus.addr);
    mvprintw(13, 8, "data:\t0x%04x", memory[bus.addr]);
}

// add 1 every time
static uint16_t program[] = {
    JUMP << 12 | 3,
    0,
    1,
    LOAD << 12 | 1,
    ADD  << 12 | 2,
    WRTE << 12 | 1,
    JUMP << 12 | 3
};

// answer should be 45
// static uint16_t program[] = {
//     JUMP << 12 | 6,
//     5,
//     4,
//     3,
//     2,
//     1,
//     LOAD << 12 | 1,
//     SUB  << 12 | 2,
//     WRTE << 12 | 1,
//     LOAD << 12 | 4,
//     DIV  << 12 | 5,
//     ADD  << 12 | 3,
//     MUL  << 12 | 1,
//     WRTE << 12 | 1,
//     JUMP << 12 | 1,
// };

int main()
{
    // initialise ncurses screen
    initscr();
    // initialise next state to fetch
    next_s = FETCH;
    // load in program
    memcpy(memory, program, sizeof(program));
    // loop until 'q' is pressed
    while(getch() != 'q') {
        print_debug();
        cycle();
    }
    endwin();

    return 0;
}
