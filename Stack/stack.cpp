#include <iostream>

template<class T>
class Stack{

    public:

    T* start;
    int size;
    int top;
    
    Stack(int size){
        
        this->size = size;
        this->top = -1;

        this->start = new T[size];
    }

    int size(){
        return this->size();
    }

    void push(T value){
        if(!this->isFull()){ 
            this->top += 1;
            this->start[this->top] = value;
        } else {
            std::cout << "Stack is full\n";
        }
        
    }

    T pop(){
        if(!this->isEmpty()){
            T value = this->start[this->top];
            this->top -= 1;
            return value;
        }
        std::cout << "Error: Stack don't have elements\n";
        exit(1);
    }

    bool isEmpty(){
        return (top == -1);
    }

    bool isFull(){
        return (top+1 >= size);
    }

    T topElement(){
        return this->start[this-top];
    }

    void print(){
        for(int i = 0 ; i <= top ; i++){
            std::cout << this->start[i] << " ";
        }
        std::cout << std::endl;
    }

    ~Stack(){
        delete(this->start);
    }

};
