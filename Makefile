CFLAGS = -g -Wall 
CC = g++

objects = myshell.o param.o

myshell: $(objects)
	$(CC) $(CFLAGS) -o myshell $(objects)

myshell.o: myshell.cpp param.hpp
param.o: param.cpp param.hpp

.PHONY : clean
clean: 
	rm myshell $(objects)
