/**
    \file registers.h
    \author Rhys Thomas (rt8g15@soton.ac.uk)
    \date 2017-02-10
    \brief Registers in CPU.
*/

#ifndef _REGISTERS_H
#define _REGISTERS_H

#include <stdint.h>
#include "global.h" // access to data and address bus

/**
    \brief Register structure.
    \param pc Proram counter.
    \param ir instruction register.
    \param ac Accumulator.

    Contains program counter, instruction register and accumulator.
*/
struct {
    uint16_t pc;
    uint16_t ir;
    uint16_t ac;
} regs;

// function definitions
void read_ac();
void write_ac();

#endif // _REGISTERS_H
