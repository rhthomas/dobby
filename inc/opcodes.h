/**
 * @file opcodes.h
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-10
 * @brief Definitions of opcodes.
 * @details Instruction set follows the patter of
 *  [opcode (4)][var a (6)][var b (6)] thus is a
 *  16-bit architecture.
 */

#ifndef _OPCODES_H
#define _OPCODES_H

// maths ops
#define ADD  0x1
#define SUB  0x2

// binary arithmetic
#define AND  0x3
#define OR   0x4
#define NOT  0x5
#define XOR  0x6

// bitwise manipulation
#define ROTR 0x7
#define ROTL 0x8

// memory and bit patterns
#define LOAD 0x9
#define BR   0xA
#define BRE  0xB
#define BRZ  0xC

#endif // _OPCODES_H
