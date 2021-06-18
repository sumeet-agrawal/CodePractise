
#include <iostream>
#include <vector>

class Point
{
private:
	int m_x{};
	int m_y{};
	int m_z{};

public:
	Point(int x, int y, int z)
		: m_x{ x }, m_y{ y }, m_z{ z }
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ')';
		return out;
	}
};

class Shape
{
public:
	friend std::ostream& operator<<(std::ostream& out, const Shape& shape)
	{
		return shape.print(out);
	}
	virtual ~Shape() {}
private:
	virtual std::ostream& print(std::ostream& out) const = 0;
};

class Triangle : public Shape
{
public:
	Triangle(const Point& a, const Point& b, const Point& c)
		: m_a(a)
		, m_b(b)
		, m_c(c)
	{}
private:
	std::ostream& print(std::ostream& out) const
	{
		out << "Triangle(" << m_a << ", " << m_b << ", " << m_c << ")";
		return out;
	}
	Point m_a;
	Point m_b;
	Point m_c;
};

class Circle : public Shape
{
public:
	Circle(const Point& p, int r)
		: m_c(p)
		, m_r(r)
	{}
	int getRadius() const { return m_r; }
private:
	std::ostream& print(std::ostream& out) const
	{
		out << "Circle(" << m_c << ", radius " << m_r << ")";
		return out;
	}
	Point m_c;
	int m_r;
};

int getLargestRadius(const std::vector<Shape*>& v)
{
	int max{ 0 };
	for (auto* shape : v)
	{
		if (auto circle{ dynamic_cast<Circle*>(shape) })
		{
			if (circle->getRadius() > max)
				max = circle->getRadius();
		}
	}
	return max;
}

int main()
{
	std::vector<Shape*> v{
	  new Circle{Point{1, 2, 3}, 7},
	  new Triangle{Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}},
	  new Circle{Point{4, 5, 6}, 3}
	};

	// print each shape in vector v on its own line here
	for (auto* shape : v)
	{
		std::cout << (*shape) << "\n";
	}

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	// delete each element in the vector here
	for (auto* shape : v)
	{
		delete shape;
	}

	return 0;
}