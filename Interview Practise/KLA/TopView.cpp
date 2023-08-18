#include <iostream>
#include <map>
#include <vector>

struct Node
{
    int val{};
    Node* left{};
    Node* right{};
    Node(int v):val{v}{}
};

void topview(Node* root, int lvl, std::map<int, std::pair<int, int>>& mp, int ht)
{
    if(!root)
        return;
    topview(root->left, lvl-1, mp, ht+1);
    if(mp.find(lvl)==mp.end())
        mp[lvl] = {root->val, ht};
    if(mp[lvl].second>ht)
        mp[lvl] = {root->val, ht};
    topview(root->right, lvl+1, mp, ht+1);
}

int main()
{
    /* Create following Binary Tree
         1
        / \
       2   3
        \
          4
           \
            5
              \
               6
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);
    root->left->right->left = new Node(7);
    root->left->right->left->left = new Node(8);
    std::map<int, std::pair<int, int>> mp{};
    topview(root, 0, mp, 0);
    for(auto &x: mp)
        std::cout<<x.second.first<<" ";
    std::cout<<"\n";
    return 0;
}