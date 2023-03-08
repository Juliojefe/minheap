# Julio Fernandez Makefile for p2

p2:  main.o intMinHeap.o
	g++ -o p2 main.o intMinHeap.o

main.o:  main.cpp intMinHeap.h
	g++ -c main.cpp

intMinHeap.o:  intMinHeap.cpp intMinHeap.h
	g++ -c intMinHeap.cpp

clean:
	rm -f p2 *.o *~
