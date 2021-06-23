#include <iostream>
#include <vector>

using VI = std::vector<int>;

int bs_util(const VI& vec, int min, int max, int num)
{
	int mid = (max + min) / 2;
	if (vec[mid] == num)
		return mid;
	else if (vec[mid] < vec[max])
	{
		if (num > vec[mid] && num < vec[max])
			return bs_util(vec, mid + 1, max, num);
		else
			return bs_util(vec, min, mid - 1, num);
	}
	else if (vec[min] < vec[mid])
	{
		if (num > vec[min] && num < vec[mid])
			return bs_util(vec, min, mid - 1, num);
		else
			return bs_util(vec, mid + 1, max, num);
	}
	return -1;
}

int binary_search(const VI& vec, int num)
{
	return bs_util(vec, 0, vec.size() - 1, num);
}
int main()
{
	VI vec{ 3, 4, 5, 6, 7, 8, 9, 1, 2 };
	std::cout << binary_search(vec, 1) << "\n";

	return 0;
}