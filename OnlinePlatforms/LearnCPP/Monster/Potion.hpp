#ifndef POTION
#define POTION

#include "Random.hpp"

#include <array>
#include <iostream>

class Potion
{
public:
    enum Type
    {
        health,
        strength,
        poison,
        max_types
    };
    enum Size
    {
        small,
        medium,
        large,
        max_sizes
    };
    friend std::ostream& operator<<(std::ostream& out, const Potion& p)
    {
        return out<<"You drank a "<<p.getSizeString(p.m_size)<<" potion of "<<p.getTypeString(p.m_type);
    }
    Potion()
        : m_type{static_cast<Type>(Random::get(0, max_types-1))}
        , m_size{static_cast<Size>(Random::get(0, max_sizes-1))}
    {}
    const Type getType() const { return m_type;}
    const Size getSize() const { return m_size;}
private:
    std::string_view getTypeString(Type type) const
    {
        switch(type)
        {
            case health:    return "Health";
            case strength:  return "Strength";
            case poison:    return "Poison";
        }
        return "???";
    }
    std::string_view getSizeString(Size size) const 
    {
        switch(size)
        {
            case small:     return "Small";
            case medium:    return "Medium";
            case large:     return "Large";
        }
        return "???";
    }
    Type m_type{};
    Size m_size{};
};

#endif