#include <iostream>

#include "binaryTree.cpp"

using namespace std;

int main(){

    BinarySearchTree<int> myBST;
    
    myBST.insert(100);
    myBST.insert(150);
    myBST.insert(50);
    myBST.insert(25);
    myBST.insert(12);
    myBST.insert(35);
    myBST.insert(125);
    myBST.insert(135);
    myBST.insert(200);
    myBST.insert(101);
    
    /*
    myBST.insert(1);
    myBST.insert(2);
    myBST.insert(3);
    myBST.insert(4);
    myBST.insert(5);
    myBST.insert(6);
    myBST.insert(7);
    myBST.insert(8);
    myBST.insert(9);
    myBST.insert(10);
    */

    myBST.inOrden();
    myBST.preOrden();
    myBST.posOrden();

    cout << "Height: " << myBST.height() << endl;
    cout << "Size: " << myBST.size() << endl;

    cout << myBST.verify(myBST.root) << endl;
    myBST.printNodes();

    myBST.remove(101);
    myBST.remove(12);
    myBST.remove(25);
    myBST.remove(125);
    myBST.remove(150);
    myBST.remove(50);
    myBST.remove(135);
    myBST.remove(35);
    myBST.remove(100);
    myBST.remove(200);

    cout << myBST.verify(myBST.root) << endl;
    myBST.printNodes();
    
    
    
    return 0;
}