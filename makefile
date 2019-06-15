#SRC = $(wildcard ./src/*.c)
#LIBS = $(wildcard ./libs/*.h)
#OBJ = $(subst .c,.o, $(subst src,, $(SRC)))
#FLAGS = -c -Wall -ansi -pedantic -lglut -lGL -lGLU -lm

all: boom

boom: main.o draws.o gui.o logica.o
	gcc -o boom main.o draws.o gui.o logica.o

main.o: main.c libs/draws.h libs/gui.h libs/logica.h
	gcc -o main.o main.c -c -Wall -lglut -lGL -lGLU -lm

draws.o: src/draws.c libs/draws.h
	gcc -o draws.o src/draws.c -c -Wall -lglut -lGL -lGLU -lm

gui.o: src/gui.c libs/gui.h
	gcc -o gui.o src/gui.c -c -Wall -lglut -lGL -lGLU -lm

logica.o: src/logica.c libs/logica.h
	gcc -o logica.o src/logica.c -c -Wall -lglut -lGL -lGLU -lm

#boom: $(OBJ)
#	gcc -o boom $(OBJ)

#%.o: %.c %.h
#	gcc -o $@ $< $(FLAGS)

#main.o: main.c $(LIBS)
#	gcc -o main.o main.c $(FLAGS)


