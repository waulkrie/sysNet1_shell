CFLAGS = -g -Wall 
CC = gcc

objects = myshell.o param.o

myshell: $(objects)
	$(CC) -o test $(objects)

myshell.o: myshell.cpp param.h
param.o: param.c param.h

.PHONY : clean
clean: 
	rm myshell $(objects)
