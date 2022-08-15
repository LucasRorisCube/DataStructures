#include <iostream>

#include "linkedList.cpp"

using namespace std;

int main(){


    linkedList<int> myList;

    myList.add(1);
    myList.add(3);
    myList.add(7);
    myList.add(100);

    cout << myList[2] << endl;
    cout << myList.search(100) << endl;

    myList.print();
    myList.remove(3);
    myList.print();
    cout << "######################" << endl;
    myList.reverse();

    myList.print();

    myList.add(6);
    myList.add(314);
    myList.print();
    myList.remove(1);
    myList.print();
    myList.reverse();
    myList.print();

    myList.sort();
    myList.print();

    myList.reverseSort();
    myList.print();

    //myList.removeAll();


    return 0;
}