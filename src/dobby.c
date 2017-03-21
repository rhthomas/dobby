/**
    \file dobby.c
    \author Rhys Thomas (rt8g15@soton.ac.uk)
    \date 2017-02-10
    \brief Dobby is a free emulator. Master gave Dobby his own architecture.
*/

#include "dobby.h"

int clock = 0;
uint16_t mem=0;

/**
    \brief Prints the register graphic to the terminal.
*/
void print_regs()
{
    for(int y=11; y<18; y++) {
        switch(y) {
            case 12:
                mvprintw(y, 2, "pc |  0x%04x  |", regs.pc);
                break;
            case 14:
                mvprintw(y, 2, "ir |  0x%04x  |", regs.ir);
                break;
            case 16:
                mvprintw(y, 2, "ac |  0x%04x  |", regs.ac);
                break;
            default:
                mvprintw(y, 5, "+----------+");
                break;
        }
    }
}

/**
    \brief Prints human readable state.
*/
void get_state()
{
    switch(present_s) {
        case 0000: mvprintw(3, 8, "pres:\tDECODE"); break;
        case 0001: mvprintw(3, 8, "pres:\tFETCH"); break;
        case 0002: mvprintw(3, 8, "pres:\tINC_PC"); break;
    }
    switch(next_s) {
        case 0000: mvprintw(4, 8, "next:\tDECODE"); break;
        case 0001: mvprintw(4, 8, "next:\tFETCH"); break;
        case 0002: mvprintw(4, 8, "next:\tINC_PC"); break;
    }
}

/**
    \brief Prints debug info such as register values, instructions to execute etc.
*/
void print_debug()
{
    // opcode
    mvprintw(1, 0, "Opcode:");
    mvprintw(1, 8, "%s", opcode_print);
    // current state
    mvprintw(3, 0, "State");
    get_state();
    // bus
    mvprintw(6, 0, "Bus");
    mvprintw(6, 8, "addr:\t0x%02x", bus.addr);
    mvprintw(7, 8, "data:\t0x%04x", bus.data);
    // alu
    mvprintw(9, 0, "ALU");
    mvprintw(9, 8, "input:\t0x%04x", alu_input);
    // regs
    print_regs();
    // memory
    print_mem(mem);
}

// X=(A-B)*(C+D/E)=5
// when finished, hang at addr 14
static uint16_t program[] = {
    JUMP << 12 | 6, // jump to start of program
    5,              // A
    4,              // B
    3,              // C
    2,              // D
    1,              // E
    LOAD << 12 | 1, // load A into acc
    SUB  << 12 | 2, // acc = acc-B
    WRTE << 12 | 1, // write acc (A-B) to 0x01
    LOAD << 12 | 4, // load D into acc
    DIV  << 12 | 5, // acc = acc / E
    ADD  << 12 | 3, // acc = acc + C
    MUL  << 12 | 1, // acc = acc * 0x01 (A-B)
    WRTE << 12 | 1, // write answer to 0x01 (A-B*(C+D/E))
    JUMP << 12 | 14 // loop forever
};

int main()
{
    // initialise ncurses screen with no cursor
    initscr();
    curs_set(0);
    // initialise next state to fetch
    next_s = FETCH;
    // load in program
    memcpy(memory, program, sizeof(program));

    // print initial help window
    mvprintw(0,0,"Dobby debugging suite.");
    mvprintw(1,0,"u: Move address list up.");
    mvprintw(2,0,"d: Move address list down.");
    mvprintw(3,0,"q: Quit program.");
    mvprintw(4,0,"Other keys increment program counter.");

    // loop until 'q' is pressed
    while(1) {
        char c=getch();
        clear();
        switch(c) {
            case 'u': mem = (mem < 15) ? mem+1 : 15; break;
            case 'd': mem = (mem > 0) ? mem-1 : 0; break;
            case 'q': endwin(); return 0;
            default: cycle(); break;
        }
        print_debug();
    }

    return 0;
}
