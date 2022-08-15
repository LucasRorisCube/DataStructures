all: main

run: main
	./main

main.o: main.cpp
	gcc -o main.o -c main.cpp

queue.o: queue.cpp
	gcc -o queue.o -c queue.cpp

main: main.o queue.o
	g++ -o main main.o queue.o && make clean
	
clean:
	@rm *.o