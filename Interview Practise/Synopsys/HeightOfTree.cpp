#include <iostream>

class Node
{
private:
    int data;
public:
    Node* left;
    Node* right;
    Node(int d)
        : data(d)
        , left(nullptr)
        , right(nullptr)
    {}
    int maxDepth()
    {
        if (!this)
            return 0;
        if (!(left || right))
            return 0;

        int l = left->maxDepth();
        int r = right->maxDepth();
        return (l > r ? l : r) + 1;
    }
    void destroy()
    {
        if (!this)
            return;
        left->destroy();
        left = nullptr;
        right->destroy();
        right = nullptr;
        delete this;
    }
};
int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    std::cout << "Height of tree is " << root->maxDepth();
    root->destroy();    // Only to be used if new is done
    root = nullptr;
    return 0;
}