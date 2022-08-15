#include <iostream>

template<class T>
class MaxHeap{

    public:

    T* root;
    int size;
    int currentSize;

    MaxHeap(int size){
        this->size = size;
        this->root = new T[size];
        this->currentSize = 0;
    }

    void swap(int i, int j){
        T temp = this->root[i];
        this->root[i] = this->root[j];
        this->root[j] = temp;
    }

    void push(T value){
        if(!this->isFull()){

            this->root[this->currentSize] = value;

            int index = this->currentSize;
            currentSize += 1;

            while(index != 0){
                int parent = (int)((index-1)/2);

                if(value > this->root[parent]){
                    swap(index, parent);
                    index = parent;
                } else {
                    break;
                }
            }

            
        }
    }

    T popRoot(){
        if(!this->isEmpty()){
            T valueOfRoot = this->root[0];

            this->root[0] = this->root[this->currentSize-1];
            this->currentSize -= 1;

            int index = 0;
            
            while(index < (this->currentSize-1)/2){
                int left = 2*index+1;
                int right = 2*index+2;

                if(this->root[index] < this->root[right]){
                    if(this->root[right] < this->root[left]){
                        swap(index, left);
                        index = left;
                    } else {
                        swap(index, right);
                        index = right;
                    }
                    
                } else if(this->root[index] < this->root[left]){
                    swap(index, left);
                    index = left;
                } else {
                    break;
                }
            }

            return valueOfRoot;
        } else {
            exit(1);
        }
    }

    bool isFull(){
        return (this->currentSize+1 == this->size);
    }

    bool isEmpty(){
        return (this->currentSize == 0);
    }

    void print(){
        for(int i = 0 ; i < this->currentSize ; i++){
            std::cout << this->root[i] << " ";
        }
        std::cout << std::endl;
    }

    ~MaxHeap(){
        delete(this->root);
    }

};
