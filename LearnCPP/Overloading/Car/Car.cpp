#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <string_view>

class Car
{
private:
    std::string m_make;
    std::string m_model;

public:
    Car(std::string_view make, std::string_view model)
        : m_make{ make }, m_model{ model }
    {
    }

    bool operator== (const Car& c) const { return (m_make == c.m_make && m_model == c.m_model);}
    bool operator!= (const Car& c) const { return !(*this == c);}
    bool operator<  (const Car& c) const 
    {
        if(m_make != c.m_make)
            return m_make < c.m_make;
        return m_model < c.m_model;
    }
    friend std::ostream& operator<<(std::ostream& out, const Car& c);
};

std::ostream& operator<<(std::ostream& out, const Car& c)
{
    return out<<"("<<c.m_make<<", "<<c.m_model<<")";
}

int main()
{
  std::vector<Car> cars{
    { "Toyota", "Corolla" },
    { "Honda", "Accord" },
    { "Toyota", "Camry" },
    { "Honda", "Civic" }
  };

  std::sort(cars.begin(), cars.end()); // requires an overloaded operator<

  for (const auto& car : cars)
    std::cout << car << '\n'; // requires an overloaded operator<<

  return 0;
}
/*
(Honda, Accord)
(Honda, Civic)
(Toyota, Camry)
(Toyota, Corolla)
*/