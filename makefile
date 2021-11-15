all: hw15.o
	gcc -o hw15 hw15.o

hw15.o: hw15.c
	gcc -c hw15.c

