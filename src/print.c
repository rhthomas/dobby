/***************************************************************************//**
 * @file   print.c
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @date   2017-03-21
 * @brief  Functions to print debugging suite with ncurses.
 ******************************************************************************/

#include "print.h"

void start_screen()
{
    mvprintw(0,0,"Dobby debugging suite.");
    mvprintw(1,0,"Other keys increment program counter.");
    mvprintw(2,0,"u: Move address list up.");
    mvprintw(3,0,"d: Move address list down.");
    mvprintw(4,0,"q: Quit program.");
    for(int i=0; i<2; i++) {
        mvprintw(5+i,0,"%d: Program #%d",i+1, i+1);
    }
}

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

void print_mem(int n)
{
    mvprintw(1,30,"Memory:");
    mvprintw(2,30,"Addr  | Data");
    mvprintw(3,30,"-------------");
    // print first 20 addresses in memory
    for(int y=16*n; y<16*(n+1); y++) {
        if(y == bus.addr) {
            attron(A_STANDOUT);
        }
        mvprintw(y-(16*n)+4, 30, "0x%03x | 0x%04x", y, memory[y]);
        attroff(A_STANDOUT);
    }
}

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
    mvprintw(6, 8, "addr:\t0x%03x", bus.addr);
    mvprintw(7, 8, "data:\t0x%04x", bus.data);
    // alu
    mvprintw(9, 0, "ALU");
    mvprintw(9, 8, "input:\t0x%04x", alu_input);
    // regs
    print_regs();
    // memory
    print_mem(addr);
}

#ifdef DEBUG
FILE *logfile;
void logToFile(void)
{
    logfile = fopen("dobby.log","a");
    if (logfile == NULL) {
        fprintf(stderr, "Error: unable to open logfile.\r\n");
        return;
    }
    fprintf(logfile, "opcode:            %s\r\n", opcode_print);
    fprintf(logfile, "(pres/next) state: %d/%d\r\n", present_s, next_s);
    fprintf(logfile, "(data/addr) bus:   0x%04X/0x%04X\r\n", bus.data, bus.addr);
    fprintf(logfile, "alu_input:         %d\r\n", alu_input);
    fprintf(logfile, "pc/ir/ac:          0x%04X/0x%04X/0x%04X\r\n", regs.pc, regs.ir, regs.ac);
    fprintf(logfile, "\r\n");
    fclose(logfile);
}
#endif
