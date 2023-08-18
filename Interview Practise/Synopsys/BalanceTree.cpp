#include <iostream>
#include <cmath>

class Node
{
public:
    Node* left;
    Node* right;
    int data;
    Node(int d)
        : data(d)
        , left(nullptr)
        , right(nullptr)
    {}
    bool isBalanced()
    {
        if (!this)
            return true;
        int l = left->height();
        int r = right->height();
        return (std::abs(l - r) <= 1) && left->isBalanced() && right->isBalanced();
    }
    int height()
    {
        if (!this)
            return 0;
        return std::max(left->height(), right->height()) + 1;
    }
};

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);

    if (root->isBalanced())
        std::cout << "Tree is balanced";
    else
        std::cout << "Tree is not balanced";
    return 0;
}