/**
    \file global.h
    \author Rhys Thomas (rt8g15@soton.ac.uk)
    \date 2017-02-10
    \brief Contains global program valiables and structures.
*/

#ifndef _GLOBAL_H
#define _GLOBAL_H

#include <stdint.h>

// address bus and data bus are 16 bits wide
struct {
    uint16_t data; // data bus
    uint16_t addr; // address bus
} bus;

#endif // _GLOBAL_H
