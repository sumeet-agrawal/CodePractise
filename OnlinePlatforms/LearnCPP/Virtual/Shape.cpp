#include <iostream>
#include <vector>

class Shape
{
public:
    virtual ~Shape() = default;
    virtual std::ostream& print(std::ostream&) const = 0;
    friend std::ostream& operator<<(std::ostream& out, const Shape& shape)
    {
        return shape.print(out);
    }
};

class Point
{
private:
	int m_x{};
	int m_y{};
public:
    Point(int x, int y)
		: m_x{ x }, m_y{ y }
	{}
	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		return out << "Point(" << p.m_x << ", " << p.m_y << ')';
	}
};

class Triangle: public Shape
{
public:
    Triangle(const Point& a, const Point& b, const Point& c)
        : m_a{a}, m_b{b}, m_c{c}
    {}
    std::ostream& print(std::ostream& out) const override
    {
        return out<<"Triangle("<<m_a<<", "<<m_b<<", "<<m_c<<")";
    }
private:
    Point m_a;
    Point m_b;
    Point m_c;
};

class Circle: public Shape
{
public:
    Circle(const Point& cen, int r)
        : m_center{cen}
        , m_radius{r}
    {}
    std::ostream& print(std::ostream& out) const override
    {
        return out<<"Circle("<<m_center<<", radius "<<m_radius<<")";
    }
    const int getRadius() const { return m_radius;}
private:
    Point m_center;
    int m_radius{};
};

int getLargestRadius(std::vector<Shape*> v)
{
    int radius{};
    for(const auto& x: v)
    {
        const Circle *c = dynamic_cast<const Circle*>(x);
        if(c)
            radius = std::max(radius, c->getRadius());
    }
    return radius;
}

int main()
{
	std::vector<Shape*> v{
	  new Circle{Point{ 1, 2 }, 7},
	  new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
	  new Circle{Point{ 7, 8 }, 3}
	};

	// print each shape in vector v on its own line here
    for(const auto& x: v)
        std::cout<<(*x)<<"\n";

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	// delete each element in the vector here
    for(const auto& x: v)
        delete x;

	return 0;
}