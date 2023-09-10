#include <iostream>

using namespace std;

struct Node
{
    int val{};
    Node* left{};
    Node* right{};
    Node(int n): val{n}{}
};

void traverse(Node* root)
{
    if(!root)
        return;
    traverse(root->left);
    cout<<root->val<<" ";
    traverse(root->right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    traverse(root);
    cout<<"\n";
    swap(root->left, root->right);
    traverse(root);
    cout<<"\n";
    return 0;
}