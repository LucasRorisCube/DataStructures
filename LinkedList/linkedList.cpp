#include <iostream>

template<class T>
struct node{
    node<T>* next;
    T data;
};


template<class T>
class linkedList{

    public:

    node<T>* first;
    node<T>* last;
    int size;
    
    linkedList(){
        this->first = NULL;
        this->last = NULL;
        this->size = 0;
    }

    int size(){
        return this->size;
    }
    
    void add(T value){
        if(this->first == NULL){
            node<T>* newNode = new node<T>();
            std::cout << "Criei" << std::endl;
            newNode->data = value;
            newNode->next = NULL;
            this->first = newNode;
            this->last = this->first;
        } else {
            node<T>* newNode = new node<T>();
            std::cout << "criei" << std::endl;
            newNode->data = value;
            newNode->next = NULL;
            this->last->next = newNode;
            this->last = newNode;
        }
        (this->size)++;
    }

    T get(int index){
        if(index >= size){
            std::cout << "Error, index out of range" << std::endl;
            exit(1);
        }
        int current = 0;
        node<T>* currentNode = this->first;
        while(current != index){
            currentNode = currentNode->next;
            current++;
        }
        return currentNode->data;
    }

    node<T> getNode(int index){
        if(index >= size){
            std::cout << "Error, index out of range" << std::endl;
            exit(1);
        }
        int current = 0;
        node<T>* currentNode = this->first;
        while(current != index){
            currentNode = currentNode->next;
            current++;
        }
        return currentNode;
    }

    void remove(T value){

        node<T>* currentNode = this->first;
        node<T>* prevNode = this->first;
        while(currentNode != NULL){
            if(currentNode->data == value){
                prevNode->next = currentNode->next;
                free(currentNode);
                std::cout << "Apaguei" << std::endl;
                return;
            }
            prevNode = currentNode;
            currentNode = currentNode->next;
            
        }
    }

    void removeAll(){
        node<T>* currentNode = this->first;
        node<T>* prevNode = this->first;
        while(currentNode != NULL){
            prevNode = currentNode;
            currentNode = currentNode->next;
            free(prevNode);
            std::cout << "Apaguei" << std::endl;
        }
        this->first = NULL;
        this->last = NULL;
    }

    int search(T value){
        int current = 0;
        node<T>* currentNode = this->first;
        while(currentNode != NULL){
            if(currentNode->data == value){
                return current;
            }
            currentNode = currentNode->next;
            current += 1;
        }
        return -1;
    }

    

    void print(){
        node<T>* currentNode = this->first;
        while(currentNode != NULL){
            std::cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        std::cout << std::endl;
    }

    void reverse(){

        if(this->size <= 1) return;

        node<T>* startNode = this->first;

        node<T>* currentNode = this->first->next;
        node<T>* prevNode = this->first;
        node<T>* nextNode = this->first->next->next;

        this->last = this->first;

        while(currentNode != NULL){

            nextNode = currentNode->next;
            currentNode->next = prevNode;

            prevNode = currentNode;
            currentNode = nextNode;
        }

        this->first = prevNode;
        this->last = startNode;
        this->last->next = NULL;
           
    }

    void sort(){

        node<T>* nodeToSwap = this->first;

        while(nodeToSwap != NULL){
            node<T>* lowerNode;
            T lower = nodeToSwap->data;

            node<T>* currentNode = nodeToSwap;
            while(currentNode != NULL){
                if(currentNode->data < lower){
                    lower = currentNode->data;
                    lowerNode = currentNode;

                }
                currentNode = currentNode->next;
            }

            lowerNode->data = nodeToSwap->data;
            nodeToSwap->data = lower;
            nodeToSwap = nodeToSwap->next;
        
        }

    }

    void reverseSort(){
        node<T>* nodeToSwap = this->first;

        while(nodeToSwap != NULL){
            node<T>* biggerNode = nodeToSwap;
            T bigger = nodeToSwap->data;

            node<T>* currentNode = nodeToSwap;
            while(currentNode != NULL){
                if(currentNode->data > bigger){
                    bigger = currentNode->data;
                    biggerNode = currentNode;

                }
                currentNode = currentNode->next;
            }

            biggerNode->data = nodeToSwap->data;
            nodeToSwap->data = bigger;
            nodeToSwap = nodeToSwap->next;
        
        }
    }

    T operator[](int index){
        return get(index);
    }

    ~linkedList(){
        removeAll();
    }
};
