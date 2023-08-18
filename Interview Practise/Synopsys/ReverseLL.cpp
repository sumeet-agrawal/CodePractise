#include <iostream>

class Node
{
public:
	Node* next{ nullptr };
	int data;
	Node(int d)
		: data(d)
	{}
	friend std::ostream& operator<<(std::ostream& out, Node* nd)
	{
		out << nd->data << " ";
		return out;
	}
};

class LL
{
public:
	Node* head;
	friend std::ostream& operator<<(std::ostream& out, LL& list)
	{
		Node* temp = list.head;
		while (temp)
		{
			out << temp;
			temp = temp->next;
		}
		return out;
	}
	void reverse()
	{
		reverse_util(head);
	}
	void reverse_util(Node* nd)
	{
		if (!nd)
			return;
		if (!nd->next)
		{
			head = nd;
			return;
		}
		reverse_util(nd->next);
		nd->next->next = nd;
		nd->next = nullptr;
	}
};
int main()
{
	LL list;
	list.head = new Node(1);
	list.head->next = new Node(2);
	list.head->next->next = new Node(3);
	list.head->next->next->next = new Node(4);
	std::cout << list << "\n";
	list.reverse();
	std::cout << list << "\n";

	return 0;
}