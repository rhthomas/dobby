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

// access to ac
#include "registers.h"
// access to data bus
#include "global.h"

#define MEM_SIZE 256

/**
 * @brief Writes data from bus to address in RAM.
 * @param addr Address to write bus data to.
 */
void write_ram(uint8_t addr);

/**
 * @brief Writes data from address in ROM to the data bus.
 * @param addr Address to read data from.
 */
void read_rom(uint8_t addr);

/**
 * @brief Writes data from address in RAM to the data bus.
 * @param addr Address to read data from.
 */
void read_ram(uint8_t addr);

#endif // _MEMORY_H
