# file to build
TARGET  = dobby

# src/alu.o src/decoder.o src/dobby.o src/memory.o src/registers.o
OBJECTS = $(patsubst %.c, %.o, $(wildcard src/*.c))

# tools and flags
CC     = gcc
CFLAGS = -Wall -std=c99 -I inc/

# primary targets
$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) -lncurses

# object dependencies
alu.o: inc/alu.h inc/opcodes.h inc/registers.h inc/global.h inc/decoder.h
decoder.o: inc/alu.h inc/decoder.h inc/global.h inc/memory.h inc/opcodes.h \
	inc/registers.h
memory.o: inc/global.h inc/memory.h inc/registers.h
registers.o: inc/global.h inc/registers.h

# house keeping
clean:
	@rm src/*.o $(TARGET)
