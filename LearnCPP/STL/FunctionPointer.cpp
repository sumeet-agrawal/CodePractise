#include <iostream>
#include <utility>

void selectionSort(int* array, int total, bool (*comparison)(int, int))
{
	for (int i{ 0 }; i < total - 1; i++)
	{
		int index{ i };
		for (int j{ i + 1 }; j < total; j++)
		{
			if (comparison(array[index], array[j]))
			{
				index = j;
			}
		}
		std::swap(array[i], array[index]);
	}
}

bool ascending(int a, int b)
{
	return a > b;
}

bool descending(int a, int b)
{
	return b > a;
}

bool evenFirst(int a, int b)
{
	if ((a % 2 == 0) && (b % 2 != 0))
		return false;
	if ((a % 2 != 0) && (b % 2 == 0))
		return true;
	return ascending(a, b);
}
void printArray(int* array, int total)
{
	for (int i{ 0 }; i < total; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << "\n";
}

int main()
{
	int array[]{ 3, 7, 9, 5, 6, 1, 8, 2, 4 };
	selectionSort(array, 9, ascending);
	printArray(array, 9);
	selectionSort(array, 9, descending);
	printArray(array, 9);
	selectionSort(array, 9, evenFirst);
	printArray(array, 9);
	return 0;
}