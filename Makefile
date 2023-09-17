CFLAGS = -g -Wall 
CC = g++

objects = myshell.o param.o parse.o

myshell: $(objects)
	$(CC) $(CFLAGS) -o myshell $(objects)

myshell.o: myshell.cpp param.hpp
param.o: param.cpp param.hpp
parse.o: parse.cpp parse.hpp

.PHONY : clean
clean: 
	rm myshell $(objects)
