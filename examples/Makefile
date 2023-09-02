CFLAGS = -g -Wall 
CC = gcc

objects = test.o sort.o

test: $(objects)
	$(CC) -o test $(objects)

test.o: test.c sort.h
sort.o: sort.c sort.h

.PHONY : clean
clean: 
	rm test $(objects)
