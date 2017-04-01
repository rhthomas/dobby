/***************************************************************************//**
@file   decoder.c
@author Rhys Thomas (rt8g15@soton.ac.uk)
@date   2017-02-10
@brief  Instruction decoder.
@image  html state.png
*******************************************************************************/

#include "decoder.h"

void decode()
{
    // 0b1111.0000.0000.0000
    uint8_t opcode = (regs.ir & 0xF000) >> 12;
    // 0b0000.1111.1111.1111
    uint16_t arg = regs.ir & 0x0FFF;

    switch(opcode) {
        case ADD:
        case SUB:
        case AND:
        case OR:
        case NOT:
        case XOR:
        case MUL:
        case DIV:
            // set ALU parameters
            bus.data = opcode;
            // send operation to ALU task
            alu_task = bus.data;
            // get address from instruction argument
            bus.addr = arg;
            // read data at memory[addr] to data bus
            mem_read();
            // ALU input is set to data bus
            alu_input = bus.data;
            // run an ALU computation
            alu_compute();
            // increment program counter
            next_s = INC_PC;
            break;
        case LOAD:
            opcode_print = "LOAD  ";
            // get address from instruction
            bus.addr = arg;
            // read data at address to data bus
            mem_read();
            // set accumulator to the value on the data bus
            write_ac();
            // increment program counter
            next_s = INC_PC;
            break;
        case WRTE:
            opcode_print = "WRTE  ";
            // write accumulator content to the data bus
            read_ac();
            // set address bus to instruction argument
            bus.addr = arg;
            // write data bus to address in memory
            mem_write();
            // increment program counter
            next_s = INC_PC;
            break;
        case JUMP:
            opcode_print = "JUMP  ";
            // jump to address in ROM
            regs.pc = arg;
            // get next instruction
            next_s = FETCH;
            break;
        case NOP:
            opcode_print = "NOP   ";
            // no operation, just increase program coutner
            next_s = INC_PC;
            break;
    }
}

void cycle()
{
    // update present state
    present_s = next_s;
    switch(present_s) {
        case FETCH:
            // get next instruction
            bus.addr = regs.pc;
            // read data in memory at bus.addr to bus.data
            mem_read();
            // set instruction register to value of data bus
            regs.ir = bus.data;
            // now decode fetched message
            next_s = DECODE;
            break;
        case DECODE:
            // decode instruction register
            decode();
            // next_s is defined inside decode case statements
            break;
        case INC_PC:
            // increment the program counter
            regs.pc++;
            // fetch next instruction
            next_s = FETCH;
            break;
    }
}
