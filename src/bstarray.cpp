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
    bool success;
    root = removeRecursive(root, key, success);
    return success;
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


    Node* removeRecursive(Node* node, int key, bool& success) {
        if (node == nullptr) {
            success = false;
            return node;
        }

        if (key < node->key) {
            node->leftChild = removeRecursive(node->leftChild, key, success);
        } else if (key > node->key) {
            node->rightChild = removeRecursive(node->rightChild, key, success);
        } else {
            if (node->leftChild == nullptr) {
                Node* temp = node->rightChild;
                delete node;
                success = true;
                return temp;
            } else if (node->rightChild == nullptr) {
                Node* temp = node->leftChild;
                delete node;
                success = true;
                return temp;
            } else {
                Node* temp = minValueNode(node->rightChild);
                node->key = temp->key;
                node->rightChild = removeRecursive(node->rightChild, temp->key, success);
            }
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->leftChild!= nullptr) {
            current = current->leftChild;
        }
        return current;
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

    cout << "Is the BST empty? " << (bstArray.isEmpty() ? "Yes" : "No") << endl;

    bstArray.removeBST(30);
    cout << "Inorder traversal after removing 30: ";
    bstArray.inorder();
    cout << endl;

    return 0;
}