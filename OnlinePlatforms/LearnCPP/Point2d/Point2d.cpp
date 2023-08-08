#include <iostream>
#include <math.h>

class Point2d
{
private:
    double m_x{};
    double m_y{};
public:
    Point2d(double a=0.0, double b=0.0)
        : m_x{a}
        , m_y{b}
    {}
    void print() const
    {
        std::cout<<"Point2d("<<m_x<<", "<<m_y<<")\n";
    }
    double distanceTo(const Point2d& pt) const
    {
        return std::sqrt((m_x - pt.m_x) * (m_x - pt.m_x) + (m_y - pt.m_y) * (m_y - pt.m_y));
    }
    friend double distanceFrom(const Point2d& a, const Point2d& b);
};

double distanceFrom(const Point2d& a, const Point2d& b)
{
    return std::sqrt((a.m_x - b.m_x) * (a.m_x - b.m_x) + (a.m_y - b.m_y) * (a.m_y - b.m_y));
}

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

    return 0;
}