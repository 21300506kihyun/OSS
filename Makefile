hw4.out: main.o base.o
	gcc -o hw4.out main.o base.o

main.o: base.h record.h extras.h main.c
	gcc -c -o main.o main.c

base.o: base.h record.h base.c
	gcc -c -o base.o base.c

