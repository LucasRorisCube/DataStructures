#include <iostream>

template<class T>
class Queue{

    public:

    T* start;
    int size;

    int rear;
    
    Queue(int size){
        
        this->size = size;
        this->rear = -1;

        this->start = new T[size];
    }

    void enqueue(T value){

        if(!this->isFull()){
            this->rear += 1;
            this->start[rear] = value;
        }
    }

    void dequeue(){

        for(int i = 0 ; i < this->rear ; i++){
            this->start[i] = this->start[i+1];
        }

        this->rear -= 1;
    }

    bool isEmpty(){
        return (this->rear == -1);
    }

    bool isFull(){
        return (this->rear+1 == size);
    }

    T inFront(){
        return this->start[0];
    }

    T inRear(){
        this->start[this->rear];
    }

    int sizeOfQueue(){
        return this->rear+1;
    }

    void print(){
        for(int i = 0 ; i < this->sizeOfQueue() ; i++){
            std::cout << this->start[i] << " ";
        }
        std::cout << std::endl;
    }

    ~Queue(){
        delete(this->start);
    }

};
