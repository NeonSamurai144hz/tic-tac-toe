CC = gcc
CFLAGS = -Wall
OBJ = main.o tic-tac-toe.o

all: morpion

morpion: $(OBJ)
	$(CC) -o morpion $(OBJ)

main.o: main.c tic-tac-toe.h
	$(CC) $(CFLAGS) -c main.c

tic-tac-toe.o: tic-tac-toe.c tic-tac-toe.h
	$(CC) $(CFLAGS) -c tic-tac-toe.c

clean:
	rm -f *.o morpion

