/**
    \file dobby.c
    \author Rhys Thomas (rt8g15@soton.ac.uk)
    \date 2017-02-10
    \brief Dobby is a free emulator. Master gave Dobby his own architecture.
*/

#include "dobby.h"

int clock = 0;
uint16_t mem=0;

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
    start_screen();

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
        print_debug(mem);
    }

    return 0;
}
