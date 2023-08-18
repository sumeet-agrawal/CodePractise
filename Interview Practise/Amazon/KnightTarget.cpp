#include <iostream>
#include <queue>

#define N 8

class Block
{
public:
	int x;
	int y;
	Block operator+(const Block& a)
	{
		Block t;
		t.x = x + a.x;
		t.y = y + a.y;
		return t;
	}
};

bool isTarget(const Block& a, const Block& end)
{
	return (a.x == end.x && a.y == end.y);
}

bool isValid(const Block& d)
{
	if (d.x > 0 && d.x <= 8 && d.y > 0 && d.y <= 8)
		return true;
}

int calculateMin(const Block& start, const Block& end)
{
	Block delta[]{ {1,2}, {1,-2}, {-1,2}, {-1,-2}, {2,1}, {2,-1}, {-2,1}, {-2,-1} };
	std::queue<std::pair<Block, int>> bfs{};
	bfs.push({ start, 0 });
	while (!bfs.empty())
	{
		Block temp = bfs.front().first;
		for (auto a : delta)
		{
			Block c = temp + a;
			if (isTarget(c, end))
			{
				return bfs.front().second + 1;
			}
			if (isValid(c))
			{
				bfs.push({ c, bfs.front().second + 1 });
			}
		}
		bfs.pop();
	}
	return -1;
}

int main()
{
	Block knight;
	std::cout << "Position of knight: ";
	std::cin >> knight.x >> knight.y;
	Block target;
	std::cout << "Target Position: ";
	std::cin >> target.x >> target.y;

	std::cout << calculateMin(knight, target);

	return 0;
}