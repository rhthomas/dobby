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

#include "alu.h"		// alu_compute() alu_task alu_opA alu_opB
#include "memory.h"		// read_rom() read_ram() write_ram()
#include "opcodes.h"	// defines opcodes
#include "registers.h"	// access to ac and ir
#include "global.h"		// access to data bus

// present and next state variables
enum states {DECODE, FETCH, INC_PC, ALU_COMP} present_s, next_s;

/**
 * @brief Decodes instruction register.
 */
void decode(void);

/**
 * @brief Emulates fetch-execute cycle.
 */
void cycle(void);

#endif // _DECODER_H
