#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
#include <cmath>

int getInteger()
{
	int num;
	std::cin >> num;
	return num;
}

int getRandom(int min, int max)
{
	std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	return std::uniform_int_distribution{ min, max }(mt);
}

bool startGame(std::vector<int>& vec, int total)
{
	int i{ 0 };
	int guess{};
	while (i < total)
	{
		i++;
		std::cout << "> ";
		std::cin >> guess;
		auto ptr = std::find(vec.begin(), vec.end(), guess);
		if (ptr != vec.end())
		{
			vec.erase(ptr);
			if (total - i)
			{
				std::cout << "Nice! " << total - i << " numbers left.\n";
			}
			else
			{
				std::cout << "Nice! You found all numbers, good job!\n";
				return true;
			}
		}
		else
		{
			ptr = std::min_element(vec.begin(), vec.end(), [=](int a, int b)
				{
					return std::abs(a - guess) < std::abs(b - guess);
				});
			if (std::abs(*ptr - guess) <= 4)
			{
				std::cout << guess << " is wrong! Try " << *ptr << " next time.\n";
			}
			else
			{
				std::cout << guess << " is wrong!\n";
			}
			return false;
		}
	}
	return false;
}
int main()
{
	std::cout << "Start where? ";
	int start{ getInteger() };
	std::cout << "How many? ";
	int total{ getInteger() };
	int random{ getRandom(2,4) };
	std::vector<int> vec{};
	for (int i{ start }; i < start + total; i++)
	{
		vec.push_back(i * i * random);
	}
	std::cout << "I generated " << total << " square numbers.Do you know what each number is after multiplying it by " << random << " ? \n";
	startGame(vec, total);
	return 0;
}