#include <array>
#include <cassert>
#include <iostream>

class Stack
{
private:
    std::array<int, 10> m_stack{};
    int m_size{};
public:
    void reset()
    {
        m_size=0;
    }
    bool push(int a)
    {
        if(m_size==10)
            return false;
        m_stack[m_size++] = a;
        return true;
    }
    int pop()
    {
        assert (m_size && "Can not pop empty stack");
        return m_stack[--m_size];
    }
    void print()
    {
        std::cout<<"( ";
        for(int i{};i<m_size;i++)
            std::cout<<m_stack[i]<<" ";
        std::cout<<")\n";
    }
};

int main()
{
	Stack stack;
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
