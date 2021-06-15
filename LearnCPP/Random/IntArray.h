
#ifndef INTARRAY_H
#define INTARRAY_H

#include <cassert>

class IntArray
{
public:
	IntArray() = default;
	IntArray(int len)
		: m_length(len)
	{
		assert(len >= 0);
		if (len > 0)
			m_array = new int[m_length] {};
	}
	~IntArray()
	{
		delete[] m_array;
	}
	void erase()
	{
		delete[] m_array;
		m_array = nullptr;
		m_length = 0;
	}
	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_array[index];
	}
	int getLength() const
	{
		return m_length;
	}
	void resize(int length)
	{
		if (length == m_length)
			return;
		if (length <= 0)
		{
			erase();
			return;
		}
		int* data = new int[length] {};
		int copy{ length < m_length ? length : m_length };
		for (int i{ 0 }; i < copy; i++)
		{
			data[i] = m_array[i];
		}
		delete[] m_array;
		m_length = length;
		m_array = data;
	}
	void reallocate(int length)
	{
		erase();
		assert(length > 0);
		m_length = length;
		m_array = new int[m_length] {};
	}
	void insertBefore(int value, int index)
	{
		assert(index >= 0 && index <= m_length);
		int* data = new int[m_length + 1]{};
		for (int i{ 0 }; i < index; i++)
		{
			data[i] = m_array[i];
		}
		data[index] = value;
		for (int i{ index }; i < m_length; i++)
		{
			data[i + 1] = m_array[i];
		}
		delete[] m_array;
		m_array = data;
		m_length++;
	}
	void remove(int index)
	{
		assert(index >= 0 && index < m_length);
		if (m_length == 1)
		{
			erase();
			return;
		}
		int* data = new int[m_length - 1]{};
		for (int i{ 0 }; i < index; i++)
			data[i] = m_array[i];
		for (int i{ index + 1 }; i < m_length; i++)
			data[i - 1] = m_array[i];
		delete[] m_array;
		m_array = data;
		m_length--;
	}
	void insertAtEnd(int value)
	{
		insertBefore(value, m_length);
	}
	void insertAtBeginning(int value)
	{
		insertBefore(value, 0);
	}
private:
	int* m_array{};
	int m_length{};
};

#endif