# file to build
TARGET  = dobby

# directories
SRC   = src/
INC   = inc/
BUILD = build/

# src/alu.c src/decoder.c src/dobby.c src/memory.c src/registers.c
SOURCES = $(wildcard $(SRC)*.c)
# src/alu.o src/decoder.o src/dobby.o src/memory.o src/registers.o
OBJECTS = $(patsubst $(SRC)%.c, $(BUILD)%.o, $(SOURCES))
# prepend -I for all include directories
INCDIRS = $(addprefix -I, $(INC))

# tools and flags
CC     = gcc
CFLAGS = -Wall -std=c99 $(INCDIRS)

MAKEFLAGS += --silent

# get file dependencies then build dobby
default: $(TARGET)

# primary targets
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ -lncurses

# generate object dependencies
$(OBJECTS): $(BUILD)%.o: $(SRC)%.c
	-@mkdir -p build
	@echo "CC $<"
	$(CC) $(CFLAGS) -c $< -o $@
	$(CC) $(CFLAGS) -MM -MF $(BUILD)$*.d $<

# lists dependencies for object files
# eg. alu.o: src/alu.c inc/alu.h inc/opcodes.h inc/registers.h inc/global.h \
  inc/print.h inc/decoder.h inc/memory.h 
-include $(BUILD)*.d

# compile documentation
docs:
	@doxygen

# open doxygen website
open: docs
	@open doxygen/html/index.html

# clean away build files
clean:
	-@rm $(TARGET)
	-@rm -rf doxygen/ $(BUILD)
