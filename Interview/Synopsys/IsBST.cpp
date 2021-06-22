#include <iostream>

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
    bool isBST(const Node* l = NULL, const Node* r = NULL)
    {
        if (this == NULL)
            return true;

        if (l && data < l->data)
            return false;

        if (r && data > r->data)
            return false;

        return left->isBST(l, this) && right->isBST(this, r);
    }
};

int main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    if (root->isBST())
        std::cout << "Is BST";
    else
        std::cout << "Not a BST";

    return 0;
}