#include <iostream>

class Node
{
public:
	Node* left;
	Node* right;
	int data;
	Node(int d)
		: data(d)
		, left(nullptr)
		, right(nullptr)
	{}
	int size()
	{
		if (!this)
			return 0;
		return left->size() + right->size() + 1;
	}
};

int main()
{
	Node* root = new Node(4);
	root->left = new Node(2);
	root->right = new Node(5);
	root->left->left = new Node(1);
	root->left->right = new Node(3);

	std::cout << "Size is " << root->size() << "\n";
	return 0;
}