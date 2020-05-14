hw4.out: main.o base.o extras.o
	gcc -o hw4.out main.o base.o extras.o

main.o: base.h record.h extras.h main.c
	gcc -c -o main.o main.c

base.o: base.h record.h base.c
	gcc -c -o base.o base.c

extras.o: extras.c
	gcc -c -o extras.o extras.c

