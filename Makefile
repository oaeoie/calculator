make: calculator

calculator: main.o expr.o
	gcc -o $@ $^
	rm *.o

main.o: main.c expr.h
	gcc -c main.c

expr.o: expr.c
	gcc -c expr.c

clean:
	rm calculator
