# test program that uses libfxtime
PROG = test
# library that times function execution
LIB = libfxtime
CC = gcc
FLAGS = -O4

all: $(PROG)

$(LIB).a: $(LIB).o
	ar -r $(LIB).a $(LIB).o

$(LIB).o: $(LIB).c $(LIB).h
	$(CC) $(FLAGS) -c $(LIB).c
	
$(PROG): $(PROG).c $(LIB).a
	$(CC) $(FLAGS) $(PROG).c $(LIB).a -o $(PROG)

clean:
	rm -f *.o $(LIB).a $(PROG)
