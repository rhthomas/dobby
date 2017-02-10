/**
 * @file opcodes.h
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-10
 * @brief Definitions of opcodes.
 * @details Instruction set based on 4-bit opcodes.
 */

#ifndef _OPCODES_H
#define _OPCODES_H

// data processing
#define ADD  0x0
#define SUB  0x1
#define AND  0x2
#define OR   0x3
#define NOT  0x4
#define XOR  0x5
#define ROTR 0x6
#define ROTL 0x7

// data storage (read/write)
#define LOAD 0x8
#define WRTE 0x9


// program flow control
#define JUMP 0xA
#define BR   0xB
#define BRE  0xC
#define BRZ  0xD

// data movement (might not even need this)


#endif // _OPCODES_H
