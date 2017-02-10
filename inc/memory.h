/**
 * @file memory.h
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-10
 * @brief Von Neumann system, single memory space for progam and data.
 * @details RAM and ROM both have 256 addresses with 16-bits
 *  of data width, therefore 512bytes of storage.
 */

#ifndef _MEMORY_H
#define _MEMORY_H

#define MEM_SIZE 256

/**
 * @brief Writes data to address in ROM.
 * @param data 16 bits of data stored at each address.
 * @param addr 256 addresses available, so 8-bits required.
 */
void write_rom(uint16_t data, uint8_t addr);

/**
 * @brief Reads from address in ROM.
 * @param addr 256 addresses available, so 8-bits required.
 */
void read_rom(uint8_t addr);

#endif // _MEMORY_H
