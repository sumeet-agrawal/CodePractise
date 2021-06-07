#include <iostream>
#include <utility>

int main()
{
	int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
	constexpr int length{ static_cast<int>(std::size(array)) };
	bool b_isSorted = false;
	for (int i = 0; i < length - 1; i++)
	{
		if (b_isSorted)
		{
			std::cout << "Early termination on iteration " << i << std::endl;
			break;
		}
		b_isSorted = true;
		for (int j = 0; j < length - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				std::swap(array[j], array[j + 1]);
				b_isSorted = false;
			}
		}
	}
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}