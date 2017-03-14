# dobby

University of Southampton second year ELEC2204 Computer Engineering coursework.

## Directory structure

```
.
├── Doxyfile
├── inc
│   ├── alu.h
│   ├── decoder.h
│   ├── dobby.h
│   ├── global.h
│   ├── memory.h
│   ├── opcodes.h
│   └── registers.h
├── makefile
├── output.txt
├── README.md
└── src
    ├── alu.c
	├── decoder.c
	├── dobby.c
	└── memory.c
```

## Example assembler

This simple test program initialises the values of `0` and `1` to the memory in
addresses 0x01 and 0x02. First the system jumps to 0x03, loads the contents of
0x01 into the accumulator, adds the accumulator to the contents of 0x02, writes
the result back to address 0x01 then repeats, thus repeating the +1 operation
with each loop.

```
JUMP 3
0
1
LOAD 1
ADD  2
WRTE 1
JUMP 3
```

## Output

`dobby.c` uses and ncurses interface to display the current state of the cpu,
values on the data/address bus, inputs and operations passed to the ALU, data
in particular addresses in memory as well as the data stored in the program
counter, instruction register and accumulator.

By pressing `<enter>` (actually, any key besides 'q') the system will step
through to the next state of operation. This is to help debug the operation of
the CPU.

```
Clock: 1

States  pres:   FETCH         +----------+
        next:   DECODE     pc |  0x0000  |
                              +----------+
Bus     addr:   0x0000     ir |  0x0041  |
        data:   0x0041        +----------+
                           ac |  0x0000  |
ALU     opA:    0x0000        +----------+
        opB:    0x0000
        task:   ADD

Memory  addr:   0x0000
        data:   0x0041
```

An example of the full stepped sequence for one addition cycle is shown in the
`output.txt` file.
