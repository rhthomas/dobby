TARGET = dobby

SOURCES := $(shell find * -name *.c)
OBJECTS := $(SOURCES:.c=.o)
HEADERS := $(dir $(shell find * -name *.h))

# compiler options
CC     = gcc
CFLAGS = -Wall -std=c99 -iquote "$(HEADERS)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

clean:
	rm -rf $(HEADERS) $(TARGET)

help:
	@echo "src:\t$(SOURCES)"
	@echo "obj:\t$(OBJECTS)"
