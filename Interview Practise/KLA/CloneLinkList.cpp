#include <iostream>
#include <unordered_map>

struct Node
{
    int val{};
    Node *next{}, *arbit{};
    Node(int v): val{v}{}
};

void printList(Node* head)
{
    std::cout << head->val << "("
         << head->arbit->val << ")";
    head = head->next;
    while (head != NULL) {
        std::cout << " -> " << head->val << "("
             << head->arbit->val << ")";
        head = head->next;
    }
    std::cout << std::endl;
}

Node* cloneLinkedList(Node* head)
{
    std::unordered_map<Node*, Node*> mp{};
    Node* itr{head};
    while(itr)
        mp[itr] = new Node(itr->val),
        itr = itr->next;
    itr = head;
    while(itr)
        mp[itr]->next = mp[itr->next],
        mp[itr]->arbit = mp[itr->arbit],
        itr = itr->next;
    return mp[head];
}

int main()
{
    // Creating a linked list with random pointer
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next
        = new Node(5);
    head->arbit = head->next->next;
    head->next->arbit = head;
    head->next->next->arbit
        = head->next->next->next->next;
    head->next->next->next->arbit
        = head->next->next;
    head->next->next->next->next->arbit
        = head->next;
   
    // Print the original list
    std::cout << "The original linked list:\n";
    printList(head);
   
    // Function call
    Node* sol = cloneLinkedList(head);
   
    std::cout << "The cloned linked list:\n";
    printList(sol);
   
    return 0;
}