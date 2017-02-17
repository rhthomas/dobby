/**
 * @file alu.h
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-10
 * @brief Detailing ALU arithmetic operations.
 */

#ifndef _ALU_H
#define _ALU_H

#include "opcodes.h"	// opcodes are here
#include "registers.h"	// access to accumulator
#include "global.h"		// access to data and address bus

uint8_t alu_opA, alu_opB;	// inputs to the alu
uint8_t alu_task;			// alu operations

/**
 * @brief Sets accumulator to result of ALU operation.
 *
 * Runs ALU computation on opA and opB based on the opcode provided and writes
 * the result to the accumulator.
 */
void alu_compute(void);

#endif // _ALU_H
