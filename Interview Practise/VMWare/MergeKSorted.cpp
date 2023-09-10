#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
    int val{};
    Node* next{};
    Node(int n): val{n}{}
};

void print(Node* head)
{
    while(head)
        cout<<head->val<<" ",
        head = head->next;
    cout<<"\n";
}

Node* merge(vector<Node*>& arr)
{
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<>> pq;
    for(auto &x: arr)
        pq.push({x->val, x});
    auto t = pq.top();
    pq.pop();
    Node* ans{t.second}, *itr{ans};
    if(t.second->next)
        pq.push({t.second->next->val, t.second->next});
    while(!pq.empty())
    {
        auto t = pq.top();
        pq.pop();
        itr->next = t.second;
        itr = itr->next;
        if(t.second->next)
            pq.push({t.second->next->val, t.second->next});
    }
    return ans;
}

int main()
{
    vector<Node*> arr(3);
  
    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);
    print(arr[0]);
  
    arr[1] = new Node(2);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);
    print(arr[1]);
  
    arr[2] = new Node(0);
    arr[2]->next = new Node(9);
    arr[2]->next->next = new Node(10);
    arr[2]->next->next->next = new Node(11);
    print(arr[2]);

    print(merge(arr));

    return 0;
}