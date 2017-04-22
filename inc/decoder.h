/***************************************************************************//**
 * @file   decoder.h
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @date   2017-02-10
 * @brief  Instruction decoder.
 * @image  html state.png
 ******************************************************************************/

#ifndef DECODER_H
#define DECODER_H

#include "alu.h"       // alu_compute() alu_task alu_input
#include "memory.h"    // read_rom() read_ram() write_ram()
#include "opcodes.h"   // defines opcodes
#include "registers.h" // access to ac and ir
#include "global.h"    // access to data bus
#include "print.h"     // opcode_print

/// Present and next state variables.
typedef enum state_t {
	DECODE, ///< Decode instruction.
	FETCH,  ///< Fetch instruction from memory.
	INC_PC  ///< Increment program counter.
} state_t;

state_t present_s; ///< Present state.
state_t next_s;    ///< Next state.

/**
 * @brief Decodes instruction register.
 */
void decode();

/**
 * @brief Emulates fetch-execute cycle.
 */
void cycle();

#endif // DECODER_H
