```diff
- Not currently deployable. Under active development.
```

# dobby

University of Southampton second year ELEC2204 Computer Engineering coursework.

## Directory structure

```
.
├── inc
│   ├── alu.h
│   ├── decoder.h
│   ├── global.h
│   ├── memory.h
│   ├── opcodes.h
│   └── registers.h
├── makefile
├── newh
├── README.md
└── src
    ├── alu.c
    ├── decoder.c
    ├── dobby.c
    └── memory.c
```

## Output

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
