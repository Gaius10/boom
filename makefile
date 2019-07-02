
FLAGS = -Wall -pedantic -lglut -lGL -lGLU -lm

all: boom
	rm *.o

boom: main.o logica.o cui.o
	gcc -o boom main.o logica.o cui.o $(FLAGS)

main.o: main.c libs/logica.h libs/cui.h
	gcc -o main.o main.c -c $(FLAGS)

logica.o: src/logica.c libs/logica.h
	gcc -o logica.o src/logica.c -c $(FLAGS)

cui.o: src/cui.c libs/cui.h
	gcc -o cui.o src/cui.c -c $(FLAGS)


.PHONY:
	rm *.o


