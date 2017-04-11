/***************************************************************************//**
 * @file    examples.c
 * @author  Rhys Thomas (rt8g15@soton.ac.uk)
 * @date    2017-03-29
 * @brief   Example assembly programs.
 * @details These are copied into @p memory with memcpy based on key presses.
 ******************************************************************************/

#include "examples.h" // cpu memory size

// add one to the accumulator each iteration
uint16_t adding[MEM_SIZE] = {
    JUMP << 12 | 3,
    0,
    1,
    LOAD << 12 | 1,
    ADD  << 12 | 2,
    WRTE << 12 | 1,
    JUMP << 12 | 3
};

// X=(A-B)*(C+D/E)=5
uint16_t arithmetic[MEM_SIZE] = {
    JUMP << 12 | 6, // jump to start of program
    5,              // A
    4,              // B
    3,              // C
    2,              // D
    1,              // E
    LOAD << 12 | 1, // load A into acc
    SUB  << 12 | 2, // acc = acc-B
    WRTE << 12 | 1, // write acc (A-B) to 0x01
    LOAD << 12 | 4, // load D into acc
    DIV  << 12 | 5, // acc = acc / E
    ADD  << 12 | 3, // acc = acc + C
    MUL  << 12 | 1, // acc = acc * 0x01 (A-B)
    WRTE << 12 | 1, // write answer to 0x01 (A-B*(C+D/E))
    JUMP << 12 | 14 // loop forever
};

uint16_t *examples[] = {adding, arithmetic};
