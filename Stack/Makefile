all: main

run: main
	./main

main.o: main.cpp
	gcc -o main.o -c main.cpp

stack.o: stack.cpp
	gcc -o stack.o -c stack.cpp

main: main.o stack.o
	g++ -o main main.o stack.o && make clean
	
clean:
	@rm *.o