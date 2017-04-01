/***************************************************************************//**
@file   memory.c
@author Rhys Thomas (rt8g15@soton.ac.uk)
@date   2017-02-10
@brief  Von Neumann system, single memory space for progam and data.
*******************************************************************************/

#include "memory.h"

void mem_write()
{
    // write data on bus to memory
    memory[bus.addr] = bus.data;
}

void mem_read()
{
    // write data in memory to bus
    bus.data = memory[bus.addr];
}
