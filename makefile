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

# include object dependencies
-include Makefile.deps

# primary targets
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ -lncurses

# generate object dependencies
Makefile.deps: $(SOURCES)
	$(CC) $(CFLAGS) -MM $^ > Makefile.deps

# compile documentation
docs:
	@echo "Running doxygen..."
	@doxygen

# open doxygen website
open: docs
	@open doxygen/html/index.html

# clean away build files
clean:
	@rm src/*.o $(TARGET) Makefile.deps
	@rm -rf doxygen/
