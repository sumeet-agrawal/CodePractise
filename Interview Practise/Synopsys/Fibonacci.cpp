
#include <iostream>
#include <vector>

int main()
{
	int num{};
	do
	{
		std::cout << "Enter a positive number : ";
		std::cin >> num;
	} while (num <= 0);

	std::vector<int> vec(num + 1);
	vec[0] = 0;
	vec[1] = 1;
	for (int i{ 2 }; i <= num; i++)
		vec[i] = vec[i - 1] + vec[i - 2];
	for (auto& i : vec)
	{
		std::cout << i << " ";
	}
	std::cout << "\n";
	return 0;
}