#include <iostream>

struct Node
{
    int val{};
    Node* left{};
    Node* right{};
    Node(int v):val{v}{}
};

void convertToDLL(Node* root, Node*& head, Node*& tail)
{
    if(!root)
        return;
    if(root->left)
        convertToDLL(root->left, head, tail);

    root->left = tail;
    if(tail)
        tail->right = root;
    else
        head = root;
    
    tail = root;

    if(root->right)
        convertToDLL(root->right, head, tail);
}

bool isTriplet(Node* root)
{
    Node* head{nullptr}, *tail{nullptr};
    convertToDLL(root, head, tail);
    
    Node* itr1{head}, *itr2{}, *itr3{};
    while(itr1->right)
    {
        itr2 = itr1->right;
        itr3 = tail;
        while(itr2 && itr2 != itr3)
        {
            int t = itr2->val + itr3->val + itr1->val;
            if(t==0)
                return true;
            else if(t>0)
                itr3 = itr3->left;
            else
                itr2 = itr2->right;
        }
        itr1 = itr1->right;
    }
    return false;
}

void print(Node* root)
{
    if(!root)
        return;
    print(root->left);
    std::cout<<root->val<<" ";
    print(root->right);
}

Node* insert(Node* root, int val)
{
    if(!root)
        return new Node(val);
    if(root->val > val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
int main()
{
    Node* root{};
    root = insert(root, 5);
    insert(root, -13);
    insert(root, 14);
    insert(root, -8);
    insert(root, 13);
    insert(root, 15);
    insert(root, 7);

    //print(root);
    if(isTriplet(root))
        std::cout<<"triplest exists\n";
    else
        std::cout<<"triplet not exists\n";

    return 0;
}