#include <iostream>

enum class Animal
{
      pig
    , chicken
    , goat
    , cat
    , dog
    , duck
};

std::string_view getAnimalName(Animal a)
{
    using enum Animal;
    switch(a)
    {
        case pig: return "pig";
        case chicken: return "chicken";
        case goat: return "goat";
        case cat: return "cat";
        case dog: return "dog";
        case duck: return "duck";
        default: return "???";
    }
}

void printNumberOfLegs(Animal a)
{
    using enum Animal;
    std::cout<<"A "<<getAnimalName(a)<<" has ";
    switch(a)
    {
        case pig:
        case goat:
        case cat:
        case dog: 
            std::cout<<4;
            break;
        case chicken:
        case duck:
            std::cout<<2;
            break;
        default:
            std::cout<<"???";
    }
    std::cout<<" legs.\n";
}

int main()
{
    printNumberOfLegs(Animal::cat);
    printNumberOfLegs(Animal::chicken);
    return 0;
}