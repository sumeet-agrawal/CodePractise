#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;
class Node
{
public:
    int val;
    vector<Node*> neighbors;
public:
    Node(int n)
        : val{n}
    {}
    Node* deepCopy()
    {
        unordered_map<Node*, Node*> mp;
        dfs(mp, this);
        return mp[this];   
    }
    void dfs(unordered_map<Node*, Node*>& mp, Node* cur)
    {
        if(mp[cur])
            return;
        mp[cur] = new Node(cur->val);
        for(auto &x: cur->neighbors)
        {
            dfs(mp, x);
            mp[cur]->neighbors.push_back(mp[x]);
        }
    }
    void print()
    {
        unordered_set<int> st;
        dfs1(st, this);
    }
    void dfs1(unordered_set<int>& st, Node* cur)
    {
        if(st.contains(cur->val))
            return;
        st.insert(cur->val);
        cout<<cur->val<<"(";
        for(auto &x: cur->neighbors)
            cout<<x->val<<",";
        cout<<")\n";
        for(auto &x: cur->neighbors)
            dfs1(st, x);
    }
};

int main()
{
    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);
    Node* four = new Node(4);
    one->neighbors = {two, three};
    two->neighbors = {one, three, four};
    three->neighbors = {four, two, one};
    four->neighbors = {two, three};
    one->print();
    cout<<"deepcopy\n";
    Node* deepCpy = one->deepCopy();
    deepCpy->print();

    return 0;
}