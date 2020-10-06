CFLAGS = -Wall -pedantic -std=c11 -I. -g

all: testR testA

list.o: list.c list.h
	gcc $(CFLAGS) -c list.c

testR.o: testR.c list.h
	gcc $(CFLAGS) -c testR.c

testA.o: testA.c list.h
	gcc $(CFLAGS) -c testA.c

testR: testR.o list.o
	gcc $(CFLAGS) testR.o list.o -o testR

testA: testA.o list.o
	gcc $(CFLAGS) testA.o list.o -o testA

clean:
	rm list.o testR.o testA.o
