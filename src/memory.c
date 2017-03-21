/**
    \file memory.c
    \author Rhys Thomas (rt8g15@soton.ac.uk)
    \date 2017-02-10
    \brief Von Neumann system, single memory space for progam and data.
*/

#include "memory.h"

/**
    \brief Writes data from data bus to address in memory.
*/
void mem_write()
{
    // write data on bus to memory
    memory[bus.addr] = bus.data;
}

/**
    \brief Writes data from address in memory to data bus.
*/
void mem_read()
{
    // write data in memory to bus
    bus.data = memory[bus.addr];
}

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
