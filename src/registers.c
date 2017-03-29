/**
    \file registers.c
    \author Rhys Thomas (rt8g15@soton.ac.uk)
    \date 2017-02-22
    \brief Registers in CPU.
*/

#include "registers.h"

void read_ac()
{
    bus.data = regs.ac;
}

void write_ac()
{
    regs.ac = bus.data;
}
