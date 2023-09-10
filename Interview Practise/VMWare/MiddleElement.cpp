#include <iostream>

using namespace std;

struct Node
{
    int val{};
    Node* next{};
    Node(int n): val{n}{}
};

Node* mid(Node* head)
{
    if(!head)
        return head;
    Node* slow{head}, *fast{head->next};
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    Node* itr = head->next->next->next;
    itr->next = new Node(5);
    itr->next->next = new Node(6);
    itr->next->next->next = new Node(7);
    cout<<mid(head)->val<<"\n";
    return 0;
}