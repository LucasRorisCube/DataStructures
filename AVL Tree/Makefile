all: main

run: main
	./main

main.o: main.cpp
	gcc -o main.o -c main.cpp

AVLTree.o: AVLTree.cpp
	gcc -o AVLTree.o -c AVLTree.cpp

main: main.o AVLTree.o
	g++ -o main main.o AVLTree.o && make clean
	
clean:
	@rm *.o