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
enum {DECODE, FETCH, INC_PC} present_s, next_s;

/**
 * @brief Decodes instruction register.
 */
void decode();

/**
 * @brief Emulates fetch-execute cycle.
 */
void cycle();

#endif // DECODER_H
