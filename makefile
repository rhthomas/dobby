# file to build
TARGET  = dobby

# src/alu.c src/decoder.c src/dobby.c src/memory.c src/registers.c
SOURCES = $(wildcard src/*.c)
# src/alu.o src/decoder.o src/dobby.o src/memory.o src/registers.o
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

# tools and flags
CC     = gcc
CFLAGS = -Wall -std=c99 -I inc/

# get file dependencies then build dobby
default: Makefile.deps $(TARGET)

# primary targets
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ -lncurses

# generate object dependencies
Makefile.deps: $(SOURCES)
	$(CC) $(CFLAGS) -MM $^ > Makefile.deps

# clean away build files
clean:
	@rm src/*.o $(TARGET) Makefile.deps
	@rm -rf doxygen/

# documentation
docs:
	@doxygen
	@open doxygen/html/index.html

# include object dependencies
include Makefile.deps
