#include "../header/bst.h"
#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *leftChild;
    Node *rightChild;
    Node *parent;

    Node(int k) : key(k), leftChild(nullptr), rightChild(nullptr), parent(nullptr) {}
};

class bstlinkedlist : public bst
{
    Node *root;

    Node *findNode(int key)
    {
        Node *current = root;
        while (current != nullptr && current->key != key)
        {
            if (key < current->key)
            {
                current = current->leftChild;
            }
            else
            {
                current = current->rightChild;
            }
        }
        return current;
    }

    Node *findMin(Node *node)
    {
        while (node->leftChild != nullptr)
        {
            node = node->leftChild;
        }
        return node;
    }

    void transplant(Node *u, Node *v)
    {
        if (u->parent == nullptr)
        {
            root = v;
        }
        else if (u == u->parent->leftChild)
        {
            u->parent->leftChild = v;
        }
        else
        {
            u->parent->rightChild = v;
        }
        if (v != nullptr)
        {
            v->parent = u->parent;
        }
    }

public:
    bstlinkedlist() : root(nullptr) {}

    bool isEmpty() override
    {
        return root == nullptr;
    }

    void addBST(int key, int value) override
    {
        Node *newNode = new Node(key);
        if (isEmpty())
        {
            root = newNode;
            return;
        }
        Node *parent = nullptr;
        Node *current = root;
        while (current != nullptr)
        {
            parent = current;
            if (key < current->key)
            {
                current = current->leftChild;
            }
            else
            {
                current = current->rightChild;
            }
        }
        newNode->parent = parent;
        if (key < parent->key)
        {
            parent->leftChild = newNode;
        }
        else
        {
            parent->rightChild = newNode;
        }
    }

    bool removeBST(int key) override
    {
        Node *nodeToRemove = findNode(key);
        if (nodeToRemove == nullptr)
        {
            return false;
        }

        if (nodeToRemove->leftChild == nullptr)
        {
            transplant(nodeToRemove, nodeToRemove->rightChild);
        }
        else if (nodeToRemove->rightChild == nullptr)
        {
            transplant(nodeToRemove, nodeToRemove->leftChild);
        }
        else
        {
            Node *successor = findMin(nodeToRemove->rightChild);
            if (successor->parent != nodeToRemove)
            {
                transplant(successor, successor->rightChild);
                successor->rightChild = nodeToRemove->rightChild;
                successor->rightChild->parent = successor;
            }
            transplant(nodeToRemove, successor);
            successor->leftChild = nodeToRemove->leftChild;
            successor->leftChild->parent = successor;
        }
        delete nodeToRemove;
        return true;
    }

    bool searchBST(int key) override
    {
        return findNode(key) != nullptr;
    }
};

int main()
{
    bstlinkedlist bstObj;

    // Test case 1: Add elements to the BST
    bstObj.addBST(5, 0);
    bstObj.addBST(3, 0);
    bstObj.addBST(7, 0);
    bstObj.addBST(2, 0);
    bstObj.addBST(4, 0);
    bstObj.addBST(6, 0);
    bstObj.addBST(8, 0);

    // Test case 2: Search for an element in the BST
    int keyToSearch = 4;
    bool isFound = bstObj.searchBST(keyToSearch);
    if (isFound)
    {
        cout << "Element " << keyToSearch << " found in the BST." << endl;
    }
    else
    {
        cout << "Element " << keyToSearch << " not found in the BST." << endl;
    }

    // Test case 3: Remove an element from the BST
    int keyToRemove = 7;
    bool isRemoved = bstObj.removeBST(keyToRemove);
    if (isRemoved)
    {
        cout << "Element " << keyToRemove << " removed from the BST." << endl;
    }
    else
    {
        cout << "Element " << keyToRemove << " not found in the BST." << endl;
    }

    return 0;
}
