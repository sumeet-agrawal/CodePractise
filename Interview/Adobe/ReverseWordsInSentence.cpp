#include <iostream>
#include <string>

void reverseS(std::string& str, int l, int r)
{
	while (l < r)
	{
		std::swap(str[l++], str[r--]);
	}
}

std::string reverseString(const std::string& str)
{
	std::string temp = str;

	reverseS(temp, 0, temp.length() - 1);

	for (int i{ 0 }, j{ 0 }; i <= temp.length(); i++)
	{
		if (i == temp.length() || temp[i] == ' ')
		{
			reverseS(temp, j, i - 1);
			j = i + 1;
		}
	}

	return temp;
}

int main()
{
	std::string str;
	std::getline(std::cin, str);
	std::string rev = reverseString(str);
	std::cout << str << "\n" << rev << "\n";
	return 0;
}