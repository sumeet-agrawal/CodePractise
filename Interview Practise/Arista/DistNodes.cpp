#include <iostream>

using namespace std;

struct Node
{
    int val{};
    Node* left{};
    Node* right{};
    Node(int v) : val{v}{}
};

void depth(Node* root, int a, int lvl, int& ans)
{
    if(!root)
        return;
    if(root->val == a)
    {
        ans = lvl;
        return;
    }
    depth(root->left, a, lvl+1, ans);
    depth(root->right, a, lvl+1, ans);
}

Node* lca(Node* root, int a, int b)
{
    if(!root)
        return nullptr;
    if(root->val==a || root->val==b)
        return root;
    Node* left = lca(root->left, a, b);
    Node* right = lca(root->right, a, b);
    if(!left)
        return right;
    if(!right)
        return left;
    return root;
}

int findDistance(Node* root, int a, int b)
{
    int dista{}, distb{}, distlca{};
    depth(root, a, 0, dista);
    depth(root, b, 0, distb);
    depth(root, lca(root, a, b)->val, 0, distlca);
    return dista + distb - 2*distlca;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);
    return 0;
}