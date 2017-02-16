/**
 * @file global.h
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-10
 * @brief Contains global program valiables and structures.
 */

#ifndef _GLOBAL_H
#define _GLOBAL_H

#include <stdint.h>

typedef struct bus_t {
	// data bus
	uint16_t data;
	// address bus
	uint16_t addr;
}

// address bus and data bus are 16 bits wide
bus_t bus;

#endif // _GLOBAL_H
