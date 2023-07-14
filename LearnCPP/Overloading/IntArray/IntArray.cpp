#include <cassert>
#include <iostream>

class IntArray
{
public:
    IntArray(int size)
        : m_size{size}
    {
        assert(size>0);
        m_data = new int[size]{};
    }
    IntArray(const IntArray& arr)
        : IntArray{arr.m_size}
    {
        for(int i{};i<m_size;++i)
            m_data[i] = arr.m_data[i];
    }
    ~IntArray()
    {
        delete[] m_data;
    }
    IntArray& operator=(const IntArray& arr)
    {
        if(this == &arr)
            return *this;
        delete[] m_data;
        m_size = arr.m_size;
        m_data = new int[m_size]{};
        for(int i{};i<m_size;++i)
            m_data[i] = arr.m_data[i];
        return *this;
    }
    int& operator[](int ind)
    {
        assert(ind>=0 && ind<m_size);
        return m_data[ind];
    }
    friend std::ostream& operator<<(std::ostream& out, const IntArray& arr)
    {
        for(int i{};i<arr.m_size;++i)
            out<<arr.m_data[i]<<' ';
        return out;
    }
private:
    int m_size{};
    int *m_data{};
};

IntArray fillArray()
{
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

	a[4] = 7;

	std::cout << b << '\n';

	return 0;
}