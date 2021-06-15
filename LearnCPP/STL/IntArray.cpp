#include <iostream>
#include <cassert>

class IntArray
{
public:
	IntArray(int n)
		: m_length(n)
	{
		std::cout << "Default Constructor\n";
		m_array = new int[m_length] {};
	}
	IntArray& operator=(const IntArray& arr)
	{
		std::cout << "Operator= overload\n";
		if (this == &arr)
			return *this;
		delete[] m_array;
		m_length = arr.m_length;
		m_array = new int[m_length] {};
		for (int i{ 0 }; i < m_length; i++)
		{
			m_array[i] = arr.m_array[i];
		}
		return *this;
	}
	int& operator[](int index)
	{
		std::cout << "Operator[] overlaod\n";
		assert((index >= 0) && (index < m_length));
		return m_array[index];
	}
	friend std::ostream& operator<<(std::ostream& out, IntArray& arr)
	{
		std::cout << "Operator<< overload\n";
		for (int i{ 0 }; i < arr.m_length; i++)
		{
			out << arr[i] << " ";
		}
		return out;
	}
private:
	int* m_array{ nullptr };
	int m_length;
};

IntArray fillArray()
{
	std::cout << "fillArray()\n";
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a{ fillArray() };
	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;

	std::cout << b << '\n';

	return 0;
}