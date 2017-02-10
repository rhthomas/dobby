/**
 * @file decoder.c
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-10
 * @brief Instruction decoder.
 */

#include "decoder.h"

// opcode is the uppder 4 bits
uint8_t  opcode = (/* instruction register */ & 0xF000) >> 12;
// operand A is the middle 6 bits
uint8_t  a      = (/* instruction register */ & 0x0FC0) >> 6;
// operand B is the lower 6 bits
uint8_t  b      = (/* instruction register */ & 0x003F);
// if an address is the only parameter, it is all except opcode
uint16_t c      = (/* instruction register */ & 0x0FFF);
