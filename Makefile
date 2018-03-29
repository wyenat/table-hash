CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -g
all: annu

annu: hachage.o annuaire.o
	$(CC) -o annu hachage.o annuaire.o

hachage.o: hachage.c
	$(CC) -o hachage.o -c hachage.c $(CFLAGS)

annuaire.o: annuaire.c hachage.h
	$(CC) -o annuaire.o -c annuaire.c $(CFLAGS)

clean:
	rm -f *.o

mrproper: clean
	rm -f annu
