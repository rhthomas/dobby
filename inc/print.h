/**
    \file print.h
    \author Rhys Thomas (rt8g15@soton.ac.uk)
    \date 2017-03-21
    \brief Functions to print debugging suite with ncurses.
*/

#include <ncurses.h>

#include "alu.h"       // alu_input
#include "decoder.h"   // opcode_print
#include "global.h"    // memory table highlighting
#include "memory.h"    // memory table
#include "registers.h" // print_regs

char *opcode_print;

// function definitions
void start_screen();
void print_regs();
void print_mem(int);
void get_state();
void print_debug(int);
