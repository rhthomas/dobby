/***************************************************************************//**
 * @file   dobby.c
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @date   2017-02-10
 * @brief  Dobby is a free emulator. Master gave Dobby his own architecture.
 ******************************************************************************/

#include "dobby.h"

int clock = 0;
uint16_t mem=0;

void reset()
{
    // reset data bus
    bus.data=0; bus.addr=0;
    // reset registers
    regs.pc=0; regs.ir=0; regs.ac=0;
    // reset state machine
    next_s = FETCH;
    // reset opcode
    opcode_print = NULL;
}

int main()
{
    // initialise ncurses screen with no cursor
    initscr();
    curs_set(0);
    // initialise next state to fetch
    next_s = FETCH;
    // print initial help window
    start_screen();

    // loop until 'q' is pressed
    while(1) {
        char c=getch();
        clear();
        switch(c) {
            case '1':
            case '2':
                reset();
                memcpy(memory, examples[c-49], MEM_SIZE * sizeof(uint16_t));
                break;
            // move mem list up or down
            case 'u': mem = (mem < 0xFF) ? mem+1 : 0xFF; break;
            case 'd': mem = (mem > 0x00) ? mem-1 : 0x00; break;
            // quit application
            case 'q': endwin(); return 0;
            // any other button - cycle
            default: cycle(); break;
        }
        print_debug(mem);
    }

    return 0;
}
