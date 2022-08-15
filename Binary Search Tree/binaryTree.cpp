#include <iostream>

template<class T>
struct node{
    node<T>* right;
    node<T>* left;
    T data;
};

template<class T>
class BinarySearchTree{

    public:

    node<T>* root;
    
    BinarySearchTree(){
        
        this->root = NULL;
    }

    void insert(T value){
        
        node<T>* newNode = new node<T>;
        newNode->right = NULL;
        newNode->left = NULL;
        newNode->data = value;

        if(this->root == NULL){
            this->root = newNode;
        } else {

            node<T>* currentNode = this->root;

            int flagExit = 0;
            while(flagExit != 1){
                if(value >= currentNode->data){
                    if(currentNode->right == NULL){
                        currentNode->right = newNode;
                        flagExit = 1;
                    } else {
                        currentNode = currentNode->right;
                    }
                    
                } else {
                    if(currentNode->left == NULL){
                        currentNode->left = newNode;
                        flagExit = 1;
                    } else {
                        currentNode = currentNode->left;
                    }
                }
            }
        }
    }

    void printNodesRecursive(node<T>* currentNode){
        if(currentNode == NULL) return;

        std::cout << "Current node value: " << currentNode->data << std::endl;
        if(currentNode->right != NULL){
            std::cout << "right node value: " << currentNode->right->data << std::endl;
        } else {
            std::cout << "Don't have right value" << std::endl;
        }
        if(currentNode->left != NULL){
            std::cout << "Left node value: " << currentNode->left->data << std::endl;
        } else {
            std::cout << "Don't have left value" << std::endl;
        }

        this->printNodesRecursive(currentNode->left);
        this->printNodesRecursive(currentNode->right);
    }

    bool search(T value){

        node<T>* currentNode = this->root;

        while(currentNode != NULL){

            if(currentNode->data == value) return true;

            if(value > currentNode->data){
                currentNode = currentNode->right;
            } else {
                currentNode = currentNode->left;
            }
        }

        return false;
    }

    node<T>* removeNode(node<T>* currentNode){

        if(currentNode->right == NULL && currentNode->left == NULL){
            // Without Children
            delete(currentNode);
            return NULL;
        } else if(currentNode->right != NULL && currentNode->left != NULL){
            // Two children
            node<T>* temp = currentNode->right;
            node<T>* prevTemp = currentNode;

            while(temp->left != NULL){
                prevTemp = temp;
                temp = temp->left;
            }
            if(temp->right != NULL){
                prevTemp->left = temp->right;
            }

            if(temp == currentNode->right){
                temp->right = NULL;
            } else {
                temp->right = currentNode->right;
            }
            
            temp->left = currentNode->left;
            delete(currentNode);
            return temp;

        } else if(currentNode->right == NULL){
            // Only left children
            node<T>* temp = currentNode->left;
            delete(currentNode);
            return temp;
        } else {
            // Only right children
            node<T>* temp = currentNode->right;
            delete(currentNode);
            return temp;
        }
        return NULL;
    }

    bool verify(node<T>* node){
        if(node == NULL) return true;

        bool ret = true;
        if(node->left != NULL && node->left->data > node->data){
            ret = false;
        }
        if(node->right != NULL && node->right->data < node->data){
            ret = false;
        }
        return ret && this->verify(node->left) && this->verify(node->right);
    }

    void remove(T value){
        node<T>* currentNode = this->root;
        node<T>* prevNode = NULL;

        int right = -1;
        while(currentNode != NULL){

            if(currentNode->data == value){
                if(right == 1) prevNode->right = this->removeNode(currentNode);
                else if(right == 0) prevNode->left = this->removeNode(currentNode);
                else this->root = this->removeNode(currentNode);

                break;
            }

            if(value > currentNode->data){
                prevNode = currentNode;
                currentNode = currentNode->right;
                right = 1;
            } else {
                prevNode = currentNode;
                currentNode = currentNode->left;
                right = 0;
            }
        }

    }

    void printNodes(){

        this->printNodesRecursive(this->root);
        std::cout << "\n\n";

    }

    void RecursiveInOrden(node<T>* node){
        if(node == NULL) return;
        this->RecursiveInOrden(node->left);
        std::cout << node->data << " ";
        this->RecursiveInOrden(node->right);
    }

    void RecursivePreOrden(node<T>* node){
        if(node == NULL) return;
        std::cout << node->data << " ";
        this->RecursivePreOrden(node->left);
        this->RecursivePreOrden(node->right);
    }

    void RecursivePosOrden(node<T>* node){
        if(node == NULL) return;
        this->RecursivePosOrden(node->left);
        this->RecursivePosOrden(node->right);
        std::cout << node->data << " ";
    }

    void inOrden(){
        this->RecursiveInOrden(this->root);
        std::cout << std::endl;
    }

    void preOrden(){
        this->RecursivePreOrden(this->root);
        std::cout << std::endl;
    }

    void posOrden(){
        this->RecursivePosOrden(this->root);
        std::cout << std::endl;
    }

    int max(int n1, int n2){
        return (n1 > n2)? n1 : n2;
    }

    int RecursionHeight(node<T>* node){
        if(node == NULL) return 0;
        return 1 + this->max(RecursionHeight(node->left), RecursionHeight(node->right));
    }

    int height(){
        return this->RecursionHeight(this->root);
    }

    int RecursionSize(node<T>* node){
        if(node == NULL) return 0;
        return 1 + this->RecursionSize(node->right) + this->RecursionSize(node->left);
    }

    int size(){
        return this->RecursionSize(this->root);
    }

    ~BinarySearchTree(){
        delete(this->root);
    }

};
