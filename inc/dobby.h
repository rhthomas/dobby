/**
    \file dobby.h
    \author Rhys Thomas (rt8g15@soton.ac.uk)
    \date 2017-02-17
    \brief Dobby is a free emulator. Master gave Dobby his own architecture.
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ncurses.h>

#include "alu.h"
#include "decoder.h"
#include "global.h"
#include "memory.h"
#include "opcodes.h"
#include "print.h"
#include "registers.h"
