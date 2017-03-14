/**
    \file alu.h
    \author Rhys Thomas (rt8g15@soton.ac.uk)
    \date 2017-02-10
    \brief Detailing ALU arithmetic operations.
*/

#ifndef _ALU_H
#define _ALU_H

#include "opcodes.h"   // opcodes are here
#include "registers.h" // access to accumulator
#include "global.h"    // access to data and address bus

uint8_t alu_input; // input to the alu
uint8_t alu_task;  // alu operations

/**
    \brief Sets accumulator to result of ALU operation.

    Runs ALU computation on input to ALU and accumulator based on the opcode
    provided and writes the result back to the accumulator.
 */
void alu_compute();

#endif // _ALU_H
