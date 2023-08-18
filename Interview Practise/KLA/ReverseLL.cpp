#include <iostream>

struct Node
{
    int val{};
    Node* next{};
    Node(int v):val{v}{}
};

struct LinkedList
{
    Node* head{};
    void push(int num)
    {
        Node* nd{new Node(num)};
        nd->next = head;
        head = nd;
    }
    void print()
    {
        Node *itr{head};
        while(itr)
            std::cout<<itr->val<<" ",
            itr = itr->next;
    }
    void reverse()
    {
        Node *cur{head}, *prev{nullptr}, *next{};
        while(cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }
};

int main()
{
    /* Start with the empty list */
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);
 
    std::cout << "Given linked list\n";
    ll.print();
 
    ll.reverse();
 
    std::cout << "\nReversed linked list \n";
    ll.print();
    return 0;
}