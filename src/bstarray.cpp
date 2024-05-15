#include<iostream>
#include "../header/bst.h"

using namespace std;

struct Node {
    int key;
    Node* leftChild;
    Node* rightChild;
    Node(int key) : key(key), leftChild(nullptr), rightChild(nullptr) {}
};

class bstarray : public bst {
public:
    Node* root;

    bstarray() : root(nullptr) {}
    ~bstarray() {}

    bool isEmpty() override {
        return root == nullptr;
    }

    void addBST(int key, int value) override {
        root = addRecursive(root, key, value);
    }

    bool removeBST(int key) override {
        return false; 
    }

    bool searchBST(int key) override {
        return searchRecursive(root, key);
    }

    void inorder() {
        inorderRecursive(root);
    }

private:
    Node* addRecursive(Node* current, int key, int value) {
        if (current == nullptr) {
            return new Node(key);
        }

        if (key < current->key) {
            current->leftChild = addRecursive(current->leftChild, key, value);
        } else if (key > current->key) {
            current->rightChild = addRecursive(current->rightChild, key, value);
        }

        return current;
    }

    bool searchRecursive(Node* current, int key) {
        if (current == nullptr) {
            return false;
        }

        if (key == current->key) {
            return true;
        }

        if (key < current->key) {
            return searchRecursive(current->leftChild, key);
        } else {
            return searchRecursive(current->rightChild, key);
        }
    }

    void inorderRecursive(Node* current) {
        if (current != nullptr) {
            inorderRecursive(current->leftChild);
            cout << current->key << " ";
            inorderRecursive(current->rightChild);
        }
    }
};

int main() {
    bstarray bstArray;
    bstArray.addBST(50, 1);
    bstArray.addBST(30, 2);
    bstArray.addBST(20, 3);
    bstArray.addBST(40, 4);
    bstArray.addBST(70, 5);
    bstArray.addBST(60, 6);
    bstArray.addBST(80, 7);

    cout << "Inorder traversal: ";
    bstArray.inorder();
    cout << endl;

    cout << "Search 20: " << (bstArray.searchBST(20) ? "Found" : "Not found") << endl;
    cout << "Search 90: " << (bstArray.searchBST(90) ? "Found" : "Not found") << endl;

    return 0;
}



