CC=gcc
CFLAGS=-Wall -Wextra -O3 -DNDEBUG -DHAVEGETRUSAGE -DHAVEUNLOCKEDIO

all: aiger amulet

aiger:
	gcc -O3 -DNDEBUG -c includes/aiger.c -o includes/aiger.o

amulet: amulet.c makefile
	$(CC) $(CFLAGS) -o $@ amulet.c includes/aiger.o -lgmp
clean:
	rm -f amulet makefile includes/aiger.o
