#include <iostream>

struct Node
{
    int val{};
    Node* next{};
    Node(int n): val{n}{}
};

void update(Node* ptr)
{
    Node* itr = ptr->next;
    ptr->val = itr->val;
    ptr->next = itr->next;
    delete itr;
}

int main()
{
    
    Node* nd = new Node(1);
    nd->next = new Node(5);
    nd->next->next = new Node(13);
    nd->next->next->next = new Node(20);
    nd->next->next->next->next = new Node(99);
    nd->next->next->next->next->next = new Node(24);
    update(nd->next->next->next);
    Node* itr{nd};
    while(itr)
        std::cout<<itr->val<<" ", itr=itr->next;
    return 0;
}
//l1 = 1->5->13->24->99->20->nullptr

//ptr = {20}

