/**
 * @file memory.h
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-10
 * @brief Von Neumann system, single memory space for progam and data.
 *
 * RAM and ROM both have 256 addresses with 16-bits of data width, therefore
 * 512 bytes of storage available.
 */

#ifndef _MEMORY_H
#define _MEMORY_H

#include "registers.h"	// access to accumulator
#include "global.h"		// access to data and address bus

#define MEM_SIZE 256

// memory array
uint16_t memory[MEM_SIZE];

/**
 * @brief Writes data from bus to address in memory.
 */
void mem_write(void);

/**
 * @brief Writes data from address in memory to the data bus.
 */
void mem_read(void);

#endif // _MEMORY_H
