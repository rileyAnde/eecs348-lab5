CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = matrix
all: $(TARGET)
$(TARGET): matrix.o
	$(CC) $(CFLAGS) -o $(TARGET) matrix.o

m.o: m.c
	$(CC) $(CFLAGS) -c matrix.c
clean:
	rm -f $(TARGET) *.o