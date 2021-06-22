#include <iostream>

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d)
        : data(d)
        , left(nullptr)
        , right(nullptr)
    {}
    Node* lca(int n1, int n2)
    {
        if (!this)
            return nullptr;
        if ((n1 < data) && (n2 < data))
            return left->lca(n1, n2);
        if ((n1 > data) && (n2 > data))
            return right->lca(n1, n2);
        return this;
    }
};

int main()
{
    // Let us construct the BST shown in the above figure
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    int n1 = 10, n2 = 14;
    Node* t = root->lca(n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    n1 = 14, n2 = 8;
    t = root->lca(n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    n1 = 10, n2 = 22;
    t = root->lca(n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
    return 0;
}