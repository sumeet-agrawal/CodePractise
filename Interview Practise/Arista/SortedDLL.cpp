#include <iostream>

struct Node
{
    int val{};
    Node* next{};
    Node* prev{};
    Node(int v, Node* ptr = nullptr): val{v}, prev{ptr} {}
};

using namespace std;

void update(Node* head, int k, int c)
{
    Node* itr = head, *temp;
    while(itr)
    {
        if(itr->val == k)
        {
            temp = itr;
            itr->prev->next = itr->next;
            itr->next->prev = itr->prev;
            temp->val -= c;
            break;
        }
        itr = itr->next;
    }
    itr = head;
    while(itr)
    {
        if(itr->val > temp->val)
        {
            temp->prev = itr->prev;
            temp->next = itr;
            itr->prev->next = temp;
            itr->next->prev = temp;
            break;
        }
        itr = itr->next;
    }
}

int main()
{
    Node* head = new Node(1);
    Node* itr = head;
    for(int i{3};i<=15;i+=2)
    {
        itr->next = new Node(i, itr);
        itr = itr->next;
    }
    update(head, 7, 3);
    itr = head;
    while(itr)
    {
        cout<<itr->val<<" ";
        itr = itr->next;
    }
    cout<<"\n";
    return 0;
}