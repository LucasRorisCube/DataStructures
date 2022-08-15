all: main

run: main
	./main

main.o: main.cpp
	gcc -o main.o -c main.cpp

minHeap.o: minHeap.cpp
	gcc -o minHeap.o -c minHeap.cpp

main: main.o minHeap.o
	g++ -o main main.o minHeap.o && make clean
	
clean:
	@rm *.o