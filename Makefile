CC=clang
CFLAGS=-std=c99 -Wall -Wextra -g
all: annu test

annu: hachage.o annuaire.o
	$(CC) -o annu hachage.o annuaire.o

test: hachage.o test_creer.o
	$(CC) -o test hachage.o test_creer.o

hachage.o: hachage.c
	$(CC) -o hachage.o -c hachage.c $(CFLAGS)

annuaire.o: annuaire.c hachage.h
	$(CC) -o annuaire.o -c annuaire.c $(CFLAGS)

test_creer.o: test_creer.c hachage.h
	$(CC) -o test_creer.o -c test_creer.c $(CFFLAGS)

clean:
	rm -f *.o

mrproper: clean
	rm -f annu
