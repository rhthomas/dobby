/**
    \file print.c
    \author Rhys Thomas (rt8g15@soton.ac.uk)
    \date 2017-03-21
    \brief Functions to print debugging suite with ncurses.
*/

#include "print.h"

/**
    \brief Prints debugger instructions to the terminal.
*/
void start_screen()
{
    mvprintw(0,0,"Dobby debugging suite.");
    mvprintw(1,0,"u: Move address list up.");
    mvprintw(2,0,"d: Move address list down.");
    mvprintw(3,0,"q: Quit program.");
    mvprintw(4,0,"Other keys increment program counter.");
}

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
    \brief Prints memory contents to display in the form of a table.
    \param n Address range to display, eg. n=0 shows addr 0x0 to 0xF.
*/
void print_mem(int n)
{
    mvprintw(1,30,"Memory:");
    mvprintw(2,30,"Addr | Data");
    mvprintw(3,30,"-------------");
    // print first 20 addresses in memory
    for(int y=16*n; y<16*(n+1); y++) {
        if(y == bus.addr) {
            attron(A_STANDOUT);
        }
        mvprintw(y-(16*n)+4, 30, "0x%02x | 0x%04x", y, memory[y]);
        attroff(A_STANDOUT);
    }
}

/**
    \brief Prints present and next state in human readable form.
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
    \brief Prints debug info such as memory, registers, opcodes etc.
    \param addr Address range to display.
    \see print_mem
*/
void print_debug(int addr)
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
    print_mem(addr);
}
