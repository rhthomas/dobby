/**
 * @file memory.c
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-10
 * @brief Von Neumann system, single memory space for progam and data.
 */

#include "memory.h"

// memory array
uint16_t memory[MEM_SIZE];

void mem_write(void)
{
	// write data on bus to memory
	memory[bus.addr] = bus.data;
}

void mem_read(void)
{
	// write data in memory to bus
	bus.data = memory[bus.addr];
}
