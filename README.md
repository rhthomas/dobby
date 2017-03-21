# dobby

University of Southampton second year ELEC2204 Computer Engineering coursework.

## Directory structure

```
.
├── Doxyfile
├── Makefile
├── README.md
├── inc
│   ├── alu.h
│   ├── decoder.h
│   ├── dobby.h
│   ├── global.h
│   ├── memory.h
│   ├── opcodes.h
│   └── registers.h
└── src
    ├── alu.c
    ├── decoder.c
    ├── dobby.c
    ├── memory.c
    └── registers.c
```

## Build instructions

For this project I have made a Makefile to simplify compilation of the files
and their dependencies. This means that if one or two files are changed the
compiler only rebuilds the changed files, thus reducing compile time. To run the
Makefile there are a number of options,
* `make`, builds code to `dobby` executable.
* `make clean`, cleans directiory of build files (`*.o`, `dobby`, `doxygen/` and `Makefile.deps`).
* `make docs`, calls Doxygen to generate code documentation.

```
gcc -Wall -std=c99 -I inc/ -MM src/alu.c src/decoder.c src/dobby.c src/memory.c src/registers.c > Makefile.deps
gcc -Wall -std=c99 -I inc/   -c -o src/alu.o src/alu.c
gcc -Wall -std=c99 -I inc/   -c -o src/decoder.o src/decoder.c
gcc -Wall -std=c99 -I inc/   -c -o src/dobby.o src/dobby.c
gcc -Wall -std=c99 -I inc/   -c -o src/memory.o src/memory.c
gcc -Wall -std=c99 -I inc/   -c -o src/registers.o src/registers.c
gcc -o dobby src/alu.o src/decoder.o src/dobby.o src/memory.o src/registers.o -lncurses
```

## Example assembly

\f[ X = (A-B) * \left(C+\frac{D}{E}\right) \f]

```
JUMP 6
5
4
3
2
1
LOAD 1
SUB  2
WRTE 1
LOAD 4
DIV  5
ADD  3
MUL  1
WRTE 1
JUMP 1
```

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
u: Move address list up.
d: Move address list down.
q: Quit program.
Other keys increment program counter.
```

### Operation

```
Opcode: JUMP                  Memory:
                              Addr | Data
State   pres:   FETCH         -------------
        next:   DECODE        0x00 | 0xa006
                              0x01 | 0x0005
Bus     addr:   0x06          0x02 | 0x0004
        data:   0x8001        0x03 | 0x0003
                              0x04 | 0x0002
ALU     input:  0x0000        0x05 | 0x0001
                              0x06 | 0x8001
     +----------+             0x07 | 0x1002
  pc |  0x0006  |             0x08 | 0x9001
     +----------+             0x09 | 0x8004
  ir |  0x8001  |             0x0a | 0x6005
     +----------+             0x0b | 0x0003
  ac |  0x0000  |             0x0c | 0x7001
     +----------+             0x0d | 0x9001
                              0x0e | 0xa00e
                              0x0f | 0x0000
```

It doesn't show here but in the memory table the address that the address bus
currently points to is highlighted.
