/**
    \file examples.h
    \author Rhys Thomas (rt8g15@soton.ac.uk)
    \date 2017-03-29
    \brief Example assembly programs.
    \see memory.h

    Theses are copied into \p memory with memcpy based on keyboard presses.
*/

#ifndef _EXAMPLES_H
#define _EXAMPLES_H

#include "opcodes.h" // opcodes used in assembly code
#include "memory.h"  // cpu memory size

/**
    \brief Loops forever, adding 1 to the accumulator each time.
*/
uint16_t adding[MEM_SIZE];

/**
    \brief More complex arithmetic example.
    \details \f[ X = (A-B) * \left(C+\frac{D}{E}\right) \f]
*/
uint16_t arithmetic[MEM_SIZE];

/**
    \brief Array of programs.
*/
extern uint16_t *examples[];

#endif // _EXAMPLES_H
