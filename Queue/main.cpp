#include <iostream>

#include "queue.cpp"

using namespace std;

int main(){

    Queue<int> myQueue(4);

    

    if(myQueue.isEmpty()){
        cout << "The queue is empty" << endl;
    } else {
        cout << "The queue isn't empty" << endl;
    }
    

    myQueue.enqueue(30);

    cout << "Adding the number 30 in queue" << endl;

    if(myQueue.isEmpty()){
        cout << "The queue is empty" << endl;
    } else {
        cout << "The queue isn't empty" << endl;
    }

    myQueue.enqueue(70);

    cout << "Adding the number 70 in queue" << endl;

    myQueue.print();

    myQueue.dequeue();
    cout << "Removing one element on queue" << endl;

    myQueue.print();

    myQueue.enqueue(15);
    cout << "Adding the number 15 in queue" << endl;
    myQueue.enqueue(70);
    cout << "Adding the number 70 in queue" << endl;

    if(myQueue.isFull()){
        cout << "The queue is full" << endl;
    } else {
        cout << "The queue isn't full" << endl;
    }

    myQueue.enqueue(13);
    cout << "Adding the number 13 in queue" << endl;

    if(myQueue.isFull()){
        cout << "The queue is full" << endl;
    } else {
        cout << "The queue isn't full" << endl;
    }

    myQueue.print();
    
    return 0;
}