/**
 * @file registers.c
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-22
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

void read_ac(void)
{
	bus.data = regs.ac;
}

void write_ac(void)
{
	regs.ac = bus.data;
}

#endif // _REGISTERS_H
