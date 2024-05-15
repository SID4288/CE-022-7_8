#include<iostream>
using namespace std;


class bst{
    public:
       virtual bool isEmpty() = 0;
       virtual void addBST(int) = 0;
       virtual bool removeBST(int) = 0;
       virtual bool searchBST(int) = 0;
       
};