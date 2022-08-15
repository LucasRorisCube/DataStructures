all: main

run: main
	./main

main.o: main.cpp
	gcc -o main.o -c main.cpp

binaryTree.o: binaryTree.cpp
	gcc -o binaryTree.o -c binaryTree.cpp

main: main.o binaryTree.o
	g++ -o main main.o binaryTree.o && make clean
	
clean:
	@rm *.o