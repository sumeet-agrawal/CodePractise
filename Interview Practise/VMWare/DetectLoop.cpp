#include <iostream>

using namespace std;

struct Node
{
    int val{};
    Node* next{};
    Node(int n): val{n}{}
};

bool detect(Node* head)
{
    if(!head)
        return false;
    Node *slow{head}, *fast{head->next};
    while(fast)
    {
        if(fast == slow || fast->next == slow)
            return true;
        if(!fast->next)
            return false;
        fast = fast->next->next;
        slow = slow->next;
    }
    return false;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;
    if(detect(head))
        cout<<"Loop\n";
    else
        cout<<"No Loop\n";
    return 0;
}