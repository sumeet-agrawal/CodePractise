#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct Node
{
    int val{};
    Node* left{};
    Node* right{};
    Node(int n): val{n}{}
};

void mirror(Node* root, Node* copy)
{
    if(!root)
        return;
    stack<pair<Node*, Node*>> st;
    st.push({root, copy});
    auto pushLeft = [&](Node* itr, Node* itr2){
        while(itr->left)
            st.push({itr->left, itr2->right = new Node(itr->left->val)}),
            itr = itr->left, itr2 = itr2->right;
    };
    pushLeft(root, copy);
    while(!st.empty())
    {
        auto [itr, itr2] = st.top();
        st.pop();
        if(!itr->right)
            continue;
        st.push({itr->right, itr2->left = new Node(itr->right->val)});
        pushLeft(itr->right, itr2->left);
    }
}

void mirrorCopy(Node* root, Node* copy)
{
    if(!root)
        return;
    if(root->left)
        copy->right = new Node(root->left->val),
        mirrorCopy(root->left, copy->right);
    if(root->right)
        copy->left = new Node(root->right->val),
        mirrorCopy(root->right, copy->left);
}

void traversal(Node* root)
{
    if(!root)
        return;
    traversal(root->left);
    cout<<root->val<<" ";
    traversal(root->right);
}

void levelTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        auto t = q.front();
        q.pop();
        cout<<t->val<<" ";
        if(t->left)
            q.push(t->left);
        if(t->right)
            q.push(t->right);
    }
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
    
    //traversal(root);
    levelTraversal(root);
    cout<<"\n";
    
    Node* copy = new Node(root->val);
    mirror(root, copy);
    
    //traversal(copy);
    levelTraversal(copy);
    cout<<"\n";

    return 0;
}