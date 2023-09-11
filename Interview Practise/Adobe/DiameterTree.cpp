#include <iostream>

using namespace std;

struct Node
{
    int val{};
    Node* left{};
    Node* right{};
    Node(int n): val{n}{}
};

int diameter(Node* root, int& dia)
{
    if(!root)
        return 0;
    int l = diameter(root->left, dia);
    int r = diameter(root->right, dia);
    dia = max(dia, l+r+1);
    return max(l, r) +1;
}

int main()
{
    int ans{};
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    diameter(root, ans);
    cout<<"Diameter of tree = "<<ans<<"\n";
    return 0;
}