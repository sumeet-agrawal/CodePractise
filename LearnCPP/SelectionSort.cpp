#include <iostream>
#include <utility>

int main()
{
	int array[]{ 30, 50, 20, 10, 40 };
	constexpr int length{ static_cast<int>(std::size(array)) };

	int s_index = 0;
	for (int j = 0; j < length; j++)
	{
		for (int i = j + 1; i < length; i++)
		{
			if (array[i] < array[s_index])
			{
				s_index = i;
			}
		}
		std::swap(array[j], array[s_index]);
	}
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}