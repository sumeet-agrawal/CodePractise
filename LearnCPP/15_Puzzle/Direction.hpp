#ifndef DIRECTION_MOVEMENT
#define DIRECTION_MOVEMENT

#include <iostream>

class Direction
{
public:
    enum Type
    {
        up,
        left,
        right,
        down,
        max_directions
    };
    Direction(Type type)
        : m_dir{type}
    {}
    Type getType() const { return m_dir; }
    Direction operator-() const;
    friend std::ostream& operator<<(std::ostream& out, const Direction& dir);
    std::string_view getDirectionString() const;
    static Direction getRandomDirection();
private:
    Type m_dir{};
};

#endif