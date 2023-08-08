#include "Direction.hpp"
#include "Random.hpp"

Direction Direction::operator-() const
{
    switch(m_dir)
    {
        case up:    return {down};
        case down:  return {up};
        case left:  return {right};
        case right: return {left};
    }
    return {max_directions};
}

std::ostream& operator<<(std::ostream& out, const Direction& dir)
{
    out<<"You entered direction: "<<dir.getDirectionString();
    return out;
}

std::string_view Direction::getDirectionString() const
{
    switch(m_dir)
    {
        case down:  return "down";
        case up:    return "up";
        case right: return "right";
        case left:  return "left";
    }
    return "???";
}

Direction Direction::getRandomDirection()
{
    return {static_cast<Direction::Type>(Random::get(0, Type::max_directions-1))};
}