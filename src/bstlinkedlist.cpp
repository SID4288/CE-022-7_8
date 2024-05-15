#include "../header/bst.h"
class Node{
    public:
    int key;
    Node* leftChild;
    Node* rightChild;
    Node* parent;
};
class bstlinkedlist : public bst {
    Node* root;

public:
    bstlinkedlist()
    {
        root=nullptr;
    }

    bool isEmpty(){
        return root == nullptr;
    }

    void addBST(int key)  {
        Node* newNode = new Node();
        newNode->key = key;
        newNode->leftChild = nullptr;
        newNode->rightChild = nullptr;
        newNode->parent = nullptr;
        if (isEmpty()) {
            root = newNode;
        }
        else {
            Node* temp = root;
            while (temp != nullptr) {
                if (key < temp->key) {
                    if (temp->leftChild == nullptr) {
                        temp->leftChild = newNode;
                        newNode->parent = temp;
                        break;
                    }
                    else {
                        temp = temp->leftChild;
                    }
                }
                else {
                    if (temp->rightChild == nullptr) {
                        temp->rightChild = newNode;
                        newNode->parent = temp;
                        break;
                    }
                    else {
                        temp = temp->rightChild;
                    }
                }
            }
        }
       
    }

    bool removeBST(int key)  {
        if(isEmpty()){
            return false;
        }
        Node* temp = root;
        while (temp != nullptr) {
            if (key == temp->key) {
                if (temp->leftChild == nullptr && temp->rightChild == nullptr) {
                    if (temp->parent->leftChild == temp) {
                        temp->parent->leftChild = nullptr;
                    }
                    else {
                        temp->parent->rightChild = nullptr;
                    }
                    delete temp;
                }
                else if (temp->leftChild != nullptr && temp->rightChild == nullptr) {
                    if (temp->parent->leftChild == temp) {
                        temp->parent->leftChild = temp->leftChild;
                    }
                    else {
                        temp->parent->rightChild = temp->leftChild;
                    }
                    delete temp;
                }
                else if (temp->leftChild == nullptr && temp->rightChild != nullptr) {
                    if (temp->parent->leftChild == temp) {
                        temp->parent->leftChild = temp->rightChild;
                    }
                    else {
                        temp->parent->rightChild = temp->rightChild;
                    }
                    delete temp;
                }
                else {
                    Node* min = temp->rightChild;
                    while (min->leftChild != nullptr) {
                        min = min->leftChild;
                    }
                    temp->key = min->key;
                    if (min->parent->leftChild == min) {
                        min->parent->leftChild = nullptr;
                    }
                    else {
                        min->parent->rightChild = nullptr;
                    }
                    delete min;
                }
                return true;
            }
            else if (key < temp->key) {
                temp = temp->leftChild;
            }
            else {
                temp = temp->rightChild;
            }
        }
       
       
    }

    bool searchBST(int key)  {
        if(isEmpty()){
            return false;
        }
        Node* temp = root;
        while (temp != nullptr) {
            if (key == temp->key) {
                return true;
            }
            else if (key < temp->key) {
                temp = temp->leftChild;
            }
            else {
                temp = temp->rightChild;
            }
        }
        return false;
        
    }
};