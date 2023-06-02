es14: main.o liste.o
	gcc -o es14 es14_2.o es14_3.o
main.o: es14_3.c es14_1.h
	gcc -c es14_3.c
liste.o: es14_2.c es14_1.h
	gcc -c es14_2.c