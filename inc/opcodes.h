/**
 * @file opcodes.h
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created Fri 10 Feb 2017
 */

#ifndef _OPCODES_H
#define _OPCODES_H

// maths ops
#define ADD 0x1 /**< Add x and y. */
#define SUB 0x2 /**< Subtract x and y. */

// binary arithmetic
#define AND 0x3
#define OR  0x4
#define NOT 0x5
#define XOR 0x6

// bitwise manipulation
#define ROT 0x7
#define SFT 0x8

#endif // _OPCODES_H
