CC = gcc
CFLAGS = -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self

all: ferry

ferry: principal.o user.o
	$(CC) $(CFLAGS) -o ferry principal.o user.o

principal.o: principal.c user.h
	$(CC) $(CFLAGS) -c principal.c

user.o: user.c user.h
	$(CC) $(CFLAGS) -c user.c

clean:
	rm -f *.o ferry

run: all
	./ferry