/***************************************************************************//**
@file   memory.h
@author Rhys Thomas (rt8g15@soton.ac.uk)
@date   2017-02-10
@brief  Von Neumann system, single memory space for progam and data.
*******************************************************************************/

#ifndef MEMORY_H
#define MEMORY_H

#include "registers.h" // access to accumulator
#include "global.h"    // access to data and address bus

#define MEM_SIZE 4096

/// CPU memory block.
uint16_t memory[MEM_SIZE];

/**
 * @brief Writes data from data bus to address in memory.
 */
void mem_write();

/**
 * @brief Writes data from address in memory to data bus.
 */
void mem_read();

#endif // MEMORY_H
