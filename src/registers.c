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

#include "registers.h"

void read_ac(void)
{
	bus.data = regs.ac;
}

void write_ac(void)
{
	regs.ac = bus.data;
}

