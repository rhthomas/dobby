/**
 * @file global.h
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-10
 * @brief Contains global program valiables and structures.
 */

#ifndef _GLOBAL_H
#define _GLOBAL_H

typedef struct /* some name */ {
	// zero flag for alu
	uint8_t z:1;
} /* some name */;

// bus is 16-bits wide, 4 dedicated to opcodes.
uint16_t bus_data;

#endif // _GLOBAL_H
