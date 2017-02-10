/**
 * @file registers.h
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-10
 * @brief Registers in CPU.
 */

#ifndef _REGISTERS_H
#define _REGISTERS_H

#include <stdint.h>

/**
 * @brief Program counter.
 */
uint16_t pc;

/**
 * @brief Instruction register.
 */
uint16_t ir;

/**
 * @brief Accumulator.
 */
uint16_t ac;

#endif // _REGISTERS_H
