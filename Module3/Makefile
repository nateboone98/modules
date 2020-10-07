CFLAGS = -Wall -pedantic -std=c11 -I. -g

all: testR testA testG testP

list.o: list.c list.h
	gcc $(CFLAGS) -c list.c

testR.o: testR.c list.h
	gcc $(CFLAGS) -c testR.c

testA.o: testA.c list.h
	gcc $(CFLAGS) -c testA.c

testG.o: testG.c list.h
	gcc $(CFLAGS) -c testG.c

testP.o: testP.c list.h
	gcc $(CFLAGS) -c testP.c

testR: testR.o list.o
	gcc $(CFLAGS) testR.o list.o -o testR

testA: testA.o list.o
	gcc $(CFLAGS) testA.o list.o -o testA

testG: testG.o list.o
	gcc $(CFLAGS) testG.o list.o -o testG

testP: testP.o list.o
	gcc $(CFLAGS) testP.o list.o -o testP

clean:
	rm list.o testR.o testA.o testG.o testP.o
