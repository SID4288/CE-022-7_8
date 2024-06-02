class bst
{
public:
    virtual bool isEmpty() = 0;
    virtual void addBST(int key, int value) = 0;
    virtual bool removeBST(int key) = 0;
    virtual bool searchBST(int key) = 0;
};
