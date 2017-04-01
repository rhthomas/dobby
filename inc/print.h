/***************************************************************************//**
@file   print.h
@author Rhys Thomas (rt8g15@soton.ac.uk)
@date   2017-03-21
@brief  Functions to print debugging suite with ncurses.
*******************************************************************************/

#ifndef PRINT_H
#define PRINT_H

#include <ncurses.h>

#include "alu.h"       // alu_input
#include "decoder.h"   // opcode_print
#include "examples.h"  // examples array size
#include "global.h"    // memory table highlighting
#include "memory.h"    // memory table
#include "registers.h" // print_regs

/// Opcode translated into string for printing.
char *opcode_print;

/**
 * @brief Prints debugger instructions to the terminal.
 */
void start_screen();

/**
 * @brief Prints the register graphic to the terminal.
 */
void print_regs();

/**
 * @brief Prints memory contents to display in the form of a table.
 * @param n Address range to display, eg. n=0 shows addr 0x0 to 0xF.
*/
void print_mem(int n);

/**
 * @brief Prints present and next state in human readable form.
*/
void get_state();

/**
 * @brief Prints debug info such as memory, registers, opcodes etc.
 * @param addr Address range to display.
 * @see   print_mem
 */
void print_debug(int addr);

#endif // PRINT_H
