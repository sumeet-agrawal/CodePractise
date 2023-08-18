#include <iostream>
#include <functional>

class ExpressionTree
{
public:
	char value{ 'n' };
	int num{ 0 };
	ExpressionTree* left{ nullptr };
	ExpressionTree* right{ nullptr };
	ExpressionTree(int n)
		: num(n)
	{}
	ExpressionTree(char ch)
		: value(ch)
	{}
	std::function<int(int, int)> getfptr(char ch)
	{
		switch (ch)
		{
		default:
		case '+': return [](int a, int b) {return (a + b); };
		case '-': return [](int a, int b) {return (a - b); };
		case '*': return [](int a, int b) {return (a * b); };
		case '/': return [](int a, int b) {return (a / b); };
		}
		return nullptr;
	}
	int solve()
	{
		if (!this)
			return 0;
		std::cout << value << " " << num << "\n";
		if (value == 'n')
			return num;
		auto fptr = getfptr(value);
		value = 'n';
		num = fptr(left->solve(), right->solve());
		return num;
	}
};

int main()
{
	ExpressionTree* tree = new ExpressionTree('*');
	tree->left = new ExpressionTree(2);
	tree->right = new ExpressionTree('+');
	tree->right->left = new ExpressionTree(3);
	tree->right->right = new ExpressionTree(5);

	std::cout << tree->solve() << '\n';

	return 0;
}

