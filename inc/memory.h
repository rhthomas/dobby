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

#define MEM_SIZE 256

/**
 * @brief Writes data to address in RAM.
 * @param addr Writes data from ac to one of 256 available addresses.
 */
void write_ram(uint8_t addr);

/**
 * @brief Reads from address in ROM.
 * @param addr Address to read data from.
 * @return 16-bit value stored in rom[addr].
 */
uint16_t read_rom(uint8_t addr);

/**
 * @brief Reads from address in RAM.
 * @param addr Address to read data from.
 * @return 16-bit value stored in ram[addr].
 */
uint16_t read_ram(uint8_t addr);

#endif // _MEMORY_H
