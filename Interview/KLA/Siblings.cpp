#include <iostream>
#include <queue>

struct Node
{
    int val{};
    Node* left{};
    Node* right{};
    Node(int num): val{num}{}
};

void printCousins(Node* root, Node* find)
{
    if(!root)
        return ;
    std::queue<Node*> q{};
    q.push(root);
    bool found{};
    while(!q.empty())
    {
        int n{static_cast<int>(q.size())};
        while(n--)
        {
            auto t = q.front();
            q.pop();
            if(t->left == find || t->right == find)
                found=true;
            else
            {
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            
        }
        if(found)
        {
            while(!q.empty())
                std::cout<<q.front()->val<<" ",
                q.pop();
            std::cout<<"\n";
            return;
        }
    }
}

int main()
{
    Node* root= new Node(1);
    Node* itr{root};
    itr->left = new Node(2);
    itr->right = new Node(3);
    itr = root->left;
    itr->left = new Node(4);
    itr->right = new Node(5);
    itr = root->right;
    itr->left = new Node(6);
    itr->right = new Node(7);
    printCousins(root, root->left->right);
    return 0;
}