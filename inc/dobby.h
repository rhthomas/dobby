/**
 * @file dobby.h
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-17
 * @brief Dobby is a free emulator. Master gave Dobby his own architecture.
 */

#include <stdio.h>
#include <stdint.h>
#include <ncurses.h>

#include "alu.h"
#include "decoder.h"
#include "global.h"
#include "memory.h"
#include "opcodes.h"
#include "registers.h"

int clock = 0;

/**
 * @brief Prints the register graphic to the terminal.
 */
void print_regs(void);

/**
 * @brief Prints human readable state.
 */
void get_state(void);

/**
 * @brief Prints human readable ALU operation.
 */
void get_task(void);

/**
 * @brief Prints debug info such as register values, instructions to execute etc.
 */
void print_debug(void);
