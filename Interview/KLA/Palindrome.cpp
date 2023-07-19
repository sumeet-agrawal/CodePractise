#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    int val{};
    Node *ptr{};
};

bool isPalin(Node* head)
{
    stack<int> st{};
    Node *itr{head};
    while(itr)
    {
        cout<<itr->val<<"\n";
        st.push(itr->val);
        itr = itr->ptr;
    }
    itr = head;
    cout<<st.size()<<" Size\n";
    while(itr && itr->val==st.top())
    {
        cout<<itr->val<<" "<<st.top()<<"\n";
        st.pop();
        itr = itr->ptr;
    }
    if(st.empty())
        return true;
    return false;
}

int main()
{
    // Addition of linked list
    Node one =  Node(1);
    Node two = Node(2);
    Node three = Node(3);
    Node four = Node(2);
    Node five = Node(1);
 
    // Initialize the next pointer
    // of every current pointer
    five.ptr = NULL;
    one.ptr = &two;
    two.ptr = &three;
    three.ptr = &four;
    four.ptr = &five;
    Node* temp = &one;
 
     
    // Call function to check
    // palindrome or not
    if(isPalin(&one))
        cout << "isPalindrome is true";
    else
        cout << "isPalindrome is false";
 
    return 0;
}