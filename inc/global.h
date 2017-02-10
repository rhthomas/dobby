/**
 * @file global.h
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-10
 * @brief Contains global program valiables and structures.
 */

#ifndef _GLOBAL_H
#define _GLOBAL_H

typedef struct bus_t {
	uint8_t z:1;   // zero flag from ALU
	uint16_t data; // data currently on bus
} bus_t;

// bus is 16-bits wide, 4 dedicated to opcodes.
bus_t bus;

#endif // _GLOBAL_H
