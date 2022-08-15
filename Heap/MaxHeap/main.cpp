#include <iostream>

#include "maxHeap.cpp"

using namespace std;

int main(){

    MaxHeap<int> myHeap(6);

    myHeap.push(10);
    myHeap.print();
    myHeap.push(15);
    myHeap.print();
    myHeap.push(6);
    myHeap.print();
    myHeap.push(3);
    myHeap.print();
    myHeap.push(1);
    myHeap.print();

    myHeap.popRoot();
    myHeap.print();
    myHeap.popRoot();
    myHeap.print();
    myHeap.popRoot();
    myHeap.print();
    myHeap.popRoot();
    myHeap.print();
    
    return 0;
}