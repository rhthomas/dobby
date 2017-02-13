/**
 * @file alu.h
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-10
 * @brief Detailing ALU arithmetic operations.
 */

#ifndef _ALU_H
#define _ALU_H

// defines opcodes
#include "opcodes.h"
// access to ac
#include "registers.h"
// access to data bus
#include "global.h"

/**
 * @brief Sets accumulator to result of ALU operation.
 *
 * Runs ALU computation on opA and opB based on the opcode provided and writes
 * the result to the accumulator.
 */
void alu_compute(uint8_t opcode, uint8_t opA, uint8_t opB);

/**
 * @brief Writes data from accumulator to the data bus.
 */
void ac_to_bus(void);

#endif // _ALU_H
