#include <iostream>

#include "stack.cpp"

using namespace std;

int main(){

    Stack<int> myStack(4);

    if(myStack.isEmpty()){
        cout << "The stack is empty" << endl;
    } else {
        cout << "The stack isn't empty" << endl;
    }
    

    myStack.push(30);

    cout << "Adding the number 30 in stack" << endl;

    if(myStack.isEmpty()){
        cout << "The stack is empty" << endl;
    } else {
        cout << "The stack isn't empty" << endl;
    }

    myStack.push(70);

    cout << "Adding the number 70 in stack" << endl;

    myStack.print();

    myStack.pop();
    cout << "Removing one element on stack" << endl;

    myStack.print();

    myStack.push(15);
    cout << "Adding the number 15 in stack" << endl;
    myStack.push(70);
    cout << "Adding the number 70 in stack" << endl;

    if(myStack.isFull()){
        cout << "The stack is full" << endl;
    } else {
        cout << "The stack isn't full" << endl;
    }

    myStack.push(13);
    cout << "Adding the number 13 in stack" << endl;

    if(myStack.isFull()){
        cout << "The stack is full" << endl;
    } else {
        cout << "The stack isn't full" << endl;
    }

    myStack.print();

    return 0;
}