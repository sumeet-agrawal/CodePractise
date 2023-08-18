#include <iostream>
#include <stack>

class Node
{
public:
    Node* next{ nullptr };
    char data;
    Node(char ch)
        : data(ch)
    {}
    friend std::ostream& operator<<(std::ostream& out, Node* head)
    {
        Node* temp = head;
        while (temp)
        {
            out << temp->data << "->";
            temp = temp->next;
        }
        out << "nullptr";
        return out;
    }
    static void push(Node** head, char ch)
    {
        Node* temp = new Node(ch);

        temp->next = *head;
        *head = temp;
    }
    bool isPalindrome()
    {
        std::stack<Node*> st{};
        Node* temp = this;
        while (temp)
        {
            st.push(temp);
            temp = temp->next;
        }
        temp = this;
        while (!st.empty())
        {
            if (temp && ((st.top()->data) == (temp->data)))
            {
                st.pop();
                temp = temp->next;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    /* Start with the empty list */
    Node* head = nullptr;
    char str[] = "abacaba";
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        Node::push(&head, str[i]);
        std::cout << head << "\n";
        head->isPalindrome() ? std::cout << "Is Palindrome\n\n" : std::cout << "Not Palindrome\n\n";
    }

    return 0;
}