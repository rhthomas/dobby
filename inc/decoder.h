/**
 * @file decoder.h
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-10
 * @brief Instruction decoder.
 *
 * Instructions are stored in the instruction register, ir. Top 4 bits
 * are opcodes, middle 6 are operand A and lower 6 bits are operand B. If it
 * an address is required then that is stored in operand c which consists of
 * all the bits from the ir other than the opcodes.
 */

#ifndef _DECODER_H
#define _DECODER_H

// alu_compute()
#include "alu.h"
// read_rom() read_ram() write_ram()
#include "memory.h"
// defines opcodes
#include "opcodes.h"
// access to ac and ir
#include "registers.h"

/**
 * @brief Decodes instruction register.
 */
void decode(uint16_t ir);

#endif // _DECODER_H
