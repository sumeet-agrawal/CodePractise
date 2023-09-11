#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node
{
    int val{};
    Node* left{};
    Node* right{};
    Node(int n=0): val{n}{}
};

vector<Node*> allPossible(int n, unordered_map<int, vector<Node*>>& mp)
{
    if(mp.count(n))
        return mp[n];
    if(n==1)
        return mp[n] = {new Node()};
    if(!(n&1))
        return mp[n] = {};
    vector<Node*> list;
    for(int x{1};x<n;x+=2)
    {
        int y = n-x-1;
        vector<Node*> left = allPossible(x, mp);
        vector<Node*> right = allPossible(y, mp);
        for(auto &s: left)
        {
            for(auto &t: right)
            {
                Node* nd = new Node();
                nd->left = s;
                nd->right = t;
                list.push_back(nd);
            }
        }
    }
    return mp[n] = list;
}

void display(Node* node, vector<int> &al)
{
    // If node = null then terminate the function
    if (node == nullptr) {
        return;
    }
    // If there is left child of Node node
    // then insert it into the list al
    if (node->left != nullptr) {
        al.push_back(node->left->val);
    }
   // Otherwise insert null in the list
    else {
        al.push_back(INT_MIN);
    }
      
   // Similarly, if there is right child
   // of Node node then insert it into
   // the list al
    if (node->right != nullptr) {
        al.push_back(node->right->val);
    }
   // Otherwise insert null
    else {
        al.push_back(INT_MIN);
    }
     
    // Recursively call the function
    // for left child and right child
    // of the Node node
    display(node->left, al);
    display(node->right, al);
}

int main()
{
    unordered_map<int, vector<Node*>> mp;
    vector<Node*> ans = allPossible(7, mp);
    for(auto &x: ans)
    {
        cout<<x->val<<" ";
        vector<int> pr;
        display(x, pr);
        for(auto p: pr)
            cout<<p<<" ";
        cout<<"\n";
    }
    return 0;
}