# dobby

University of Southampton second year ELEC2204 Computer Engineering coursework.

## Directory structure

```
.
├── Doxyfile
├── Makefile
├── README.md
├── build
│   ├── alu.d
│   ├── alu.o
│   ├── decoder.d
│   ├── decoder.o
│   ├── dobby.d
│   ├── dobby.o
│   ├── memory.d
│   ├── memory.o
│   ├── print.d
│   ├── print.o
│   ├── registers.d
│   └── registers.o
├── dobby
├── inc
│   ├── alu.h
│   ├── decoder.h
│   ├── dobby.h
│   ├── global.h
│   ├── memory.h
│   ├── opcodes.h
│   ├── print.h
│   └── registers.h
└── src
    ├── alu.c
    ├── decoder.c
    ├── dobby.c
    ├── memory.c
    ├── print.c
    └── registers.c
```

## Build instructions

For this project I have made a Makefile to simplify compilation of the files
and their dependencies. This means that if one or two files are changed the
compiler only rebuilds the changed files, thus reducing compile time. To run the
Makefile there are a number of options,
* `make`, builds code to `dobby` executable.
* `make clean`, cleans directory of build files (`build/`, `dobby` and `doxygen/`).
* `make docs`, calls Doxygen to generate code documentation.

```
CC src/alu.c
CC src/decoder.c
CC src/dobby.c
CC src/memory.c
CC src/print.c
CC src/registers.c
```

## Example assembly

In `examples.h` there are a number of example assembly programs. These programs
are then stores in an array called `*examples`. The examples are then copied
into memory when the user presses certain number keys.

## Output

`dobby.c` uses and ncurses interface to display the current state of the cpu,
values on the data/address bus, inputs and operations passed to the ALU, data
in particular addresses in memory as well as the data stored in the program
counter, instruction register and accumulator.

By pressing `<enter>` (actually, any key besides `<q>`) the system will step
through to the next state of operation. This is to help debug the operation of
the CPU.

The `<u>` and `<d>` keys move the memory table up/down. It is unrealistic to
print all 256 addresses to the screen at the same time.

### Start up instructions

```
Dobby debugging suite.
Other keys increment program counter.
u: Move address list up.
d: Move address list down.
q: Quit program.
1: Program #1
2: Program #2
```

### Operation

It doesn't show here but in the memory table the address that the address bus
currently points to is highlighted.

```
Opcode: JUMP                  Memory:
                              Addr  | Data
State   pres:   FETCH         -------------
        next:   DECODE        0x000 | 0xa006
                              0x001 | 0x0005
Bus     addr:   0x006         0x002 | 0x0004
        data:   0x8001        0x003 | 0x0003
                              0x004 | 0x0002
ALU     input:  0x0000        0x005 | 0x0001
                              0x006 | 0x8001
     +----------+             0x007 | 0x1002
  pc |  0x0006  |             0x008 | 0x9001
     +----------+             0x009 | 0x8004
  ir |  0x8001  |             0x00a | 0x6005
     +----------+             0x00b | 0x0003
  ac |  0x0000  |             0x00c | 0x7001
     +----------+             0x00d | 0x9001
                              0x00e | 0xa00e
                              0x00f | 0x0000
```
