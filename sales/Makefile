CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = sales
all: $(TARGET)
$(TARGET): sales.o
	$(CC) $(CFLAGS) -o $(TARGET) sales.o

s.o: s.c
	$(CC) $(CFLAGS) -c sales.c
clean:
	rm -f $(TARGET) *.o