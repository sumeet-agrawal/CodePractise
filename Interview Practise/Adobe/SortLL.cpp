#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int val{};
    Node* next{};
    Node(int n): val{n}{}
};

Node* doSort(Node* head)
{
    vector<pair<int, Node*>> vec;
    while(head)
    {
        vec.push_back({head->val, head});
        head = head->next;
    }
    sort(vec.begin(), vec.end());
    Node* itr = new Node(0);
    head = itr;
    for(auto &x: vec)
        itr->next = x.second,
        itr = itr->next;
    return head->next;
}

int main()
{
    Node* head = new Node(10);
    head->next = new Node(4);
    head->next->next = new Node(11);

    head = doSort(head);
    while(head)
    {
        cout<<head->val<<" ";
        head = head->next;
    }

    return 0;
}