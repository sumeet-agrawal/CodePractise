#include <iostream>
#include <list>
#include <queue>
#include <cmath>

class Point
{
public:
	int x;
	int y;
	Point(int a, int b)
		: x(a)
		, y(b)
	{}
	friend std::ostream& operator<<(std::ostream& out, const Point& pt)
	{
		out << "[" << pt.x << ", " << pt.y << "]";
		return out;
	}
};

class Node
{
public:
	Point pt;
	double dist{ 0 };
	Node(const Point& p)
		: pt(p)
		, dist(std::sqrt((pt.x* pt.x) + (pt.y * pt.y)))
	{}
	class Compare
	{
	public:
		bool operator()(const Node& a, const Node& b) { return a.dist > b.dist; }
	};
};

int main()
{
	std::list<Point> li{};
	li.push_back({ 1,2 });
	li.push_back({ 3,4 });
	li.push_back({ 1,-1 });
	for (auto& n : li)
	{
		std::cout << n << "\n";
	}
	std::priority_queue < Node, std::vector<Node>, Node::Compare > q{ };
	for (auto& n : li)
	{
		std::cout << "Pushing " << n << "\n";
		q.push(n);
		std::cout << "Least distance from 0,0" << q.top().pt << "\n";
	}
	int x{};
	std::cin >> x;
	for (int i{ 0 }; i < x; i++)
	{
		std::cout << q.top().pt << " ";
		q.pop();
	}
	return 0;
}