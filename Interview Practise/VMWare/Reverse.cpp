#include <iostream>

using namespace std;

struct Node
{
    int val{};
    Node* next{};
    Node(int n): val{n}{}
};

void print(Node*& head)
{
    Node* itr{head};
    while(itr)
        cout<<itr->val<<" ",
        itr = itr->next;
    cout<<"\n";
}

Node* reverse(Node*& head, int k)
{
    Node* cur{head}, *nhead{}, *nlast{};
    while(cur)
    {
        int i=k;
        Node *next{}, *prev{}, *temp{cur};
        while(cur && i--)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        if(!nhead)
            nhead = prev,
            nlast = head;
        else
        {
            nlast->next = prev;
            nlast = temp;
        }
    }
    return nhead;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    Node* ret = head->next->next->next->next;
    ret->next = new Node(6);
    ret->next->next = new Node(7);
    ret->next->next->next = new Node(8);
    print(head);
    Node* rev = reverse(head, 3);
    print(rev);
    return 0;
}