
#include <iostream>
#include <vector>
#include <cmath>

std::ostream& operator<<(std::ostream& out, const std::vector<int>& vec)
{
	for (auto& i : vec)
	{
		out << i << " ";
	}
	return out;
}

int max(int a, int b, int c)
{
	return std::max(a, std::max(b, c));
}

int maxSumArray(const std::vector<int>& arr)
{
	int mpp{ INT_MIN / 2 }, mp{ INT_MIN / 2 };
	for (std::size_t i{ 2 }; i < arr.size(); ++i)
	{
		int temp = max(arr[i], mpp + arr[i], mpp);
		mpp = mp;
		mp = temp;
	}
	return (mpp > mp ? mpp : mp);
}

int main()
{
	std::vector<int> vec{ -2, -3, 4, -1, -2, 1, 5, -3,-2,6,7,8,9,15 };
	std::cout << maxSumArray(vec) << "\n";
	return 0;
}