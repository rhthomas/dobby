/**
    \file memory.h
    \author Rhys Thomas (rt8g15@soton.ac.uk)
    \date 2017-02-10
    \brief Von Neumann system, single memory space for progam and data.
 */

#ifndef _MEMORY_H
#define _MEMORY_H

#include "registers.h" // access to accumulator
#include "global.h"    // access to data and address bus

#define MEM_SIZE 256

// memory array
uint16_t memory[MEM_SIZE];

/**
    \brief Writes data from data bus to address in memory.
*/
void mem_write();

/**
    \brief Writes data from address in memory to data bus.
*/
void mem_read();

#endif // _MEMORY_H
