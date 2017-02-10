TARGET = dobby

SOURCES := $(shell find * -name *.c)
OBJECTS := $(SOURCES:.c=.o)
HEADERS := inc/

# compiler options
CC     = gcc
CFLAGS = -Wall -std=c99 -I $(HEADERS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

clean:
	rm -rf $(OBJECTS) $(TARGET)

help:
	@echo "src:\t$(SOURCES)"
	@echo "obj:\t$(OBJECTS)"
