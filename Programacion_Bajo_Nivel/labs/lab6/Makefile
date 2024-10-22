CC = gcc
CFLAGS = -Wall -Werror
TARGET = lab6

all: $(TARGET)

$(TARGET): lab6.o
	$(CC) $(CFLAGS) -o $(TARGET) lab6.o

lab6.o: lab6.c
	$(CC) $(CFLAGS) -c lab6.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)
