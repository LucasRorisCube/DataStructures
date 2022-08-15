all: main

run: main
	./main

main.o: main.cpp
	gcc -o main.o -c main.cpp

maxHeap.o: maxHeap.cpp
	gcc -o maxHeap.o -c maxHeap.cpp

main: main.o maxHeap.o
	g++ -o main main.o maxHeap.o && make clean
	
clean:
	@rm *.o