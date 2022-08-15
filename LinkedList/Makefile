all: main

run: main
	./main

main.o: main.cpp
	gcc -o main.o -c main.cpp

linkedList.o: linkedList.cpp
	gcc -o linkedList.o -c linkedList.cpp

main: main.o linkedList.o
	g++ -o main main.o linkedList.o && make clean
	
clean:
	@rm *.o