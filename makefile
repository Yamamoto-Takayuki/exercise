.SUFFIXES: .c .o .a

LIBS=-lm
SOURCE= average.c\
				number.c\
				calc.c



.c.o:
	gcc -g -Wall -c $*.c -o $*.o

all: ex1 ex2
win: ex1.exe ex2.exe


ex1: ex1.o libex.a
	gcc -g -Wall -o $@ ex1.o -L./ -lex $(LIBS)
ex2: ex2.o libex.a
	gcc -g -Wall -o $@ ex2.o -L./ -lex $(LIBS)


ex1.exe: ex1.o libex.a
	gcc -g -Wall -o $@ ex1.o -L./ -lex $(LIBS)
ex2.exe: ex2.o libex.a
	gcc -g -Wall -o $@ ex2.o -L./ -lex $(LIBS)


libex.a: $(SOURCE:.c=.o)
	ar r $@ $(SOURCE:.c=.o)

test:
	./ex1 arg1ex1.txt arg2ex1.txt ex1output.txt

clean:
	rm -rf *.o *.exe *.a ex1 ex2

-include dependency

depend: $(SOURCE)
	gcc -M *.c > dependency
