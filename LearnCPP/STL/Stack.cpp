
#include <iostream>
#include <array>
#include <cassert>

class Stack
{
public:
	Stack()
	{
		reset();
	}
	~Stack() {}
	void reset()
	{
		m_size = 0;
	}
	void print()
	{
		std::cout << "( ";
		for (int i{ 0 }; i < m_size; i++)
		{
			std::cout << m_stack[i] << " ";
		}
		std::cout << ")\n";
	}
	bool push(int a)
	{
		if (m_size == 10)
		{
			return false;
		}
		m_stack[m_size++] = a;
		return true;
	}
	int pop()
	{
		assert(m_size > 0 && "Cannot pop empty stack");
		return m_stack[--m_size];
	}
private:
	using container_type = std::array<int, 10>;
	using size_type = container_type::size_type;
	container_type m_stack;
	size_type m_size;
};
int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}