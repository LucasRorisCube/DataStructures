#include <iostream>

template<class T>
struct node{
    node<T>* right;
    node<T>* left;
    node<T>* parent;
    int height;
    T data;
};

template<class T>
class AVLTree{

    public:

    node<T>* root;
    
    AVLTree(){
        
        this->root = NULL;
    }

    int absNum(int n){
        return (n >= 0)? n : -n;
    }

    void updateHeight(node<T>* currentNode){
        int leftHeight = (currentNode->left != NULL)? currentNode->left->height : 0;
        int rightHeight = (currentNode->right != NULL)? currentNode->right->height : 0;
        currentNode->height = 1+this->max(leftHeight, rightHeight);
    }

    void RR(node<T>* A){

        node<T>* B = A->right;
        //std::cout << ": " << A->data << "/" << B->data << std::endl;
        A->right = B->left;
        B->left = A;

        
        if(A->parent == NULL){
            this->root = B;
            B->parent = NULL;
        } else {
            B->parent = A->parent;
            B->parent->left = B;
        }

        A->parent = B;
        if(A->right != NULL) A->right->parent = A;

        //this->updateHeight(B);
        this->updateHeight(A);

    }

    void LL(node<T>* A){
        node<T>* B = A->left;
        //std::cout << ": " << A->data << "/" << B->data << std::endl;

        A->left = B->right;
        B->right = A;

        //std::cout << ": " << A->data << "/" << B->data << std::endl;
        if(A->parent == NULL){
            this->root = B;
            B->parent = NULL;
            //std::cout << "6\n";
        } else {
            //std::cout << "7\n";
            B->parent = A->parent;
            B->parent->right = B;
        }

        A->parent = B;
        if(A->left != NULL) A->left->parent = A;

        //this->updateHeight(B);
        this->updateHeight(A);
        

    }

    void balance(node<T>* currentNode, T value){

        if(value > currentNode->data){
            // R
            if(value > currentNode->right->data){
                // RR
                this->RR(currentNode);
            } else {
                // RL
                this->LL(currentNode->right);
                this->RR(currentNode);
            }
        } else {
            // L
            if(value > currentNode->left->data){
                // LR
                //std::cout << "To na LR\n";
                this->RR(currentNode->left);
                //std::cout << "Passei da RR\n";
                this->LL(currentNode);
                //std::cout << "Passei da LL\n";
            } else {
                // LL
                this->LL(currentNode);
            }
        }
    }

    void update(node<T>* currentNode, T value){
        
        while(currentNode != NULL){
            //std::cout << "3\n";
            int leftHeight = (currentNode->left != NULL)? currentNode->left->height : 0;
            int rightHeight = (currentNode->right != NULL)? currentNode->right->height : 0;
            currentNode->height = 1+this->max(leftHeight, rightHeight);
            //std::cout << rightHeight << "/" << leftHeight << std::endl;
            //this->printNodes();
            //std::cout << "4\n";
            if(this->absNum(leftHeight - rightHeight) >= 2){
                //std::cout << "4.5\n";
                this->balance(currentNode, value);
            }
            //std::cout << "1\n";
            currentNode = currentNode->parent;
            //std::cout << "2\n";
        }
    }

    void insert(T value){
        
        node<T>* newNode = new node<T>;
        newNode->right = NULL;
        newNode->left = NULL;
        newNode->height = 0;
        newNode->data = value;

        if(this->root == NULL){
            newNode->parent = NULL;
            this->root = newNode;
        } else {

            node<T>* currentNode = this->root;

            while(true){
                if(value > currentNode->data){
                    if(currentNode->right == NULL){
                        newNode->parent = currentNode;
                        currentNode->right = newNode;
                        break;
                    } else {
                        currentNode = currentNode->right;
                    }
                    
                } else {
                    if(currentNode->left == NULL){
                        newNode->parent = currentNode;
                        currentNode->left = newNode;
                        break;
                    } else {
                        currentNode = currentNode->left;
                    }
                }
                
            }

            this->update(newNode, value);

        }

    }

    void removingNode(node<T>* currentNode){

        if(currentNode->right != NULL && currentNode->left != NULL){
            // Two children
            node<T>* temp = currentNode->right;

            while(temp != NULL && temp->left != NULL){
                temp = temp->left;
            }
            
            currentNode->data = temp->data;

            node<T>* auxiliar = temp->parent;
            if(temp->right != NULL){
                
                temp->parent->left = temp->right;
                temp->right->parent = temp->parent;
                delete(temp);
                
            } else {
                if(temp->parent != currentNode){
                    temp->parent->left = NULL;
                    delete(temp);
                } else {
                    currentNode->right = NULL;
                    delete(temp);
                }
                
            }

            this->update(auxiliar, auxiliar->data);

        } else {
            if(currentNode->right != NULL){
                // One children in right
                if(currentNode->parent == NULL){
                    currentNode->right->parent = NULL;
                    this->root = currentNode->right;
                    delete(currentNode);
                    this->update(this->root, this->root->data);
                } else {
                    node<T>* auxiliar = currentNode->right;
                    if(currentNode->parent->right == currentNode){
                        currentNode->parent->right = currentNode->right;
                        currentNode->right->parent = currentNode->parent;
                        delete(currentNode);
                    } else {
                        currentNode->parent->left = currentNode->right;
                        currentNode->right->parent = currentNode->parent;
                        delete(currentNode);
                    }
                    this->update(auxiliar, auxiliar->data);
                }
            } else if(currentNode->left != NULL){
                //One children in left
                if(currentNode->parent == NULL){
                    currentNode->left->parent = NULL;
                    this->root = currentNode->left;
                    delete(currentNode);
                    this->update(this->root, this->root->data);
                } else {
                    node<T>* auxiliar = currentNode->left;
                    if(currentNode->parent->right == currentNode){
                        currentNode->parent->right = currentNode->left;
                        currentNode->left->parent = currentNode->parent;
                        delete(currentNode);
                    } else {
                        currentNode->parent->left = currentNode->left;
                        currentNode->left->parent = currentNode->parent;
                        delete(currentNode);
                    }
                    this->update(auxiliar, auxiliar->data);
                }
            } else {
                // No children
                //std::cout << "To aqui\n";
                if(currentNode->parent == NULL){
                    //std::cout << "To aqui tb\n";
                    this->root = NULL;
                    delete(currentNode);
                } else {
                    node<T>* auxiliar = currentNode->parent;
                    if(currentNode->parent->right == currentNode){
                        currentNode->parent->right = NULL;
                        delete(currentNode);
                    } else {
                        currentNode->parent->left = NULL;
                        delete(currentNode);
                    }
                    this->update(auxiliar, auxiliar->data);
                }

                //std::cout << "To aqui aaaaa\n";
            }
        }
    }

    void remove(T value){
        
        node<T>* currentNode = this->root;

        while(currentNode != NULL){

            if(currentNode->data == value){
                removingNode(currentNode);
                break;
            }

            if(value > currentNode->data){
                currentNode = currentNode->right;
            } else {
                currentNode = currentNode->left;
            }
        }

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

    void printNodesRecursive(node<T>* currentNode){
        if(currentNode == NULL) return;

        std::cout << "Current node value: " << currentNode->data << std::endl;
        std::cout << "Height: " << currentNode->height << std::endl;
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

    void printNodes(){

        this->printNodesRecursive(this->root);
        std::cout << "\n\n";

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

    ~AVLTree(){
        delete(this->root);
    }

};
