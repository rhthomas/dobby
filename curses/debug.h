/**
 * @file debug.h
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @created 2017-02-13
 * @brief Ncurses TUI for printing emulator data.
 *
 * Creates a TUI environment which displays the current state of memory, data
 * bus, opcodes, registers, ALU inputs etc. Press enter to progress the cpu,
 * ie. tick the clock.
 */

#include <ncurses.h>
