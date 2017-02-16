TARGET = debug

CC     = gcc
CFLAGS = -I. -lncurses

default: $(TARGET)

debug.o: debug.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(TARGET): debug.o
	$(CC) -o $@ $^

clean:
	rm -f $(TARGET) debug.o
