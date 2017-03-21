/**
    \file global.h
    \author Rhys Thomas (rt8g15@soton.ac.uk)
    \date 2017-02-10
    \brief Contains global program valiables and structures.
*/

#ifndef _GLOBAL_H
#define _GLOBAL_H

#include <stdint.h>

/**
    \brief Bus structure.
    \param data 16-bit data bus.
    \param addr 16-bit address bus.

    The bus is the link between the ALU, registers and memory.
*/
struct {
    uint16_t data; // data bus
    uint16_t addr; // address bus
} bus;

#endif // _GLOBAL_H
