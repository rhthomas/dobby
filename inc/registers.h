/**
 * @file registers.h
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-10
 * @brief Registers in CPU.
 *
 * +----------+
 * |    pc    |
 * +----------+
 * |    ir    |
 * +----------+
 * |    ac    |
 * +----------+
 */

#ifndef _REGISTERS_H
#define _REGISTERS_H

#include <stdint.h>
#include "global.h"	// access to data and address bus

/**
 * @brief Register structure.
 *
 * Contains program counter, instruction register and accumulator.
 */
struct {
	uint16_t pc;	// program counter
	uint16_t ir;	// instruction register
	uint16_t ac;	// accumulator
} regs;

#endif // _REGISTERS_H
