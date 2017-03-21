/**
    \file registers.c
    \author Rhys Thomas (rt8g15@soton.ac.uk)
    \date 2017-02-22
    \brief Registers in CPU.
*/

#include "registers.h"

/**
    \brief Reads value in the accumulator to the data bus.
*/
void read_ac()
{
    bus.data = regs.ac;
}

/**
    \brief Writes data bus contents to the accumulator.
*/
void write_ac()
{
    regs.ac = bus.data;
}
