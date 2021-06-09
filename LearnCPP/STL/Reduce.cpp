/*Pretend you’re writing a game where the player can hold 3 types of items : health potions, torches, and arrows.
Create an enum to identify the different types of items, and an std::array to store the number of each item the player is carrying
(The enumerators are used as indexes of the array).The player should start with 2 health potions, 5 torches, and 10 arrows.
Write a function called countTotalItems() that returns how many items the player has in total.
Have your main() function print the output of countTotalItems() as well as the number of torches.*/

#include <iostream>
#include <array>
#include <numeric>

enum class ITEM
{
	HealthPotion,
	Torches,
	Arrow,
	MaxItems
};

int countTotalItems(const std::array<int, static_cast<int>(ITEM::MaxItems)>& arr)
{
	return std::reduce(arr.begin(), arr.end());
}

int main()
{
	std::array<int, static_cast<int>(ITEM::MaxItems)> res{ 2, 5, 10 };
	std::cout << countTotalItems(res) << " " << res[static_cast<int>(ITEM::Torches)] << "\n";
	return 0;
}

