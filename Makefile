CC=clang
CFLAGS=-std=c99 -Wall -Wextra -g
all: annu test

annu: hachage.o annuaire.o
	$(CC) -o annu hachage.o annuaire.o

test: hachage.o tester.o
	$(CC) -o test hachage.o tester.o

hachage.o: hachage.c
	$(CC) -o hachage.o -c hachage.c $(CFLAGS)

annuaire.o: annuaire.c hachage.h
	$(CC) -o annuaire.o -c annuaire.c $(CFLAGS)

tester.o: tester.c hachage.h
	$(CC) -o tester.o -c tester.c $(CFFLAGS)

clean:
	rm -f *.o

mrproper: clean
	rm -f annu
