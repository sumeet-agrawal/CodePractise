#include <iostream>

class Point3d
{
private:
    int m_x{};
    int m_y{};
    int m_z{};
public:
    void setValues(int a, int b, int c)
    {
        m_x = a; m_y = b; m_z = c;
    }
    void print()
    {
        std::cout<<"<"<<m_x<<", "<<m_y<<", "<<m_z<<">\n";
    }
    bool isEqual(const Point3d& pt)
    {
        if(m_x==pt.m_x && m_y==pt.m_y && m_z==pt.m_z)
            return true;
        return false;
    }
};

int main()
{
    Point3d point1;
    point1.setValues(1, 2, 3);

    Point3d point2;
    point2.setValues(1, 2, 3);

    if (point1.isEqual(point2))
    {
        std::cout << "point1 and point2 are equal\n";
    }
    else
    {
        std::cout << "point1 and point2 are not equal\n";
    }

    Point3d point3;
    point3.setValues(3, 4, 5);

    if (point1.isEqual(point3))
    {
        std::cout << "point1 and point3 are equal\n";
    }
    else
    {
        std::cout << "point1 and point3 are not equal\n";
    }

    return 0;
}