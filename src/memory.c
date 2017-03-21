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
