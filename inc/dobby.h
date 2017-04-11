/***************************************************************************//**
 * @file   dobby.h
 * @author Rhys Thomas (rt8g15@soton.ac.uk)
 * @date   2017-02-10
 * @brief  Dobby is a free emulator. Master gave Dobby his own architecture.
 ******************************************************************************/

#ifndef DOBBY_H
#define DOBBY_H

#include <stdio.h>
#include <stdint.h>
#include <string.h> // memcpy()

#include "alu.h"
#include "decoder.h"
#include "examples.h"
#include "global.h"
#include "memory.h"
#include "opcodes.h"
#include "print.h"
#include "registers.h"

/**
 * @brief Resets registers, system bus etc. when swapping program.
 */
void reset();

#endif // DOBBY_H
