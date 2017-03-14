/**
    \file dobby.h
    \author Rhys Thomas (rt8g15@soton.ac.uk)
    \created 2017-02-17
    \brief Dobby is a free emulator. Master gave Dobby his own architecture.
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>     // required for memcpy()
#include <ncurses.h>

#include "alu.h"
#include "decoder.h"
#include "global.h"
#include "memory.h"
#include "opcodes.h"
#include "registers.h"

/**
    \brief Prints the register graphic to the terminal.
*/
void print_regs();

/**
    \brief Prints human readable state.
*/
void get_state();

/**
    \brief Prints human readable ALU operation.
*/
void get_task();

/**
    \brief Prints debug info such as register values, instructions to execute etc.
*/
void print_debug();
