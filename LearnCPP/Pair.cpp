template <typename T, typename U> // default T and U to type int
struct Pair
{
    T first{};
    U second{};
};

int main()
{
    Pair<int, int> p1{ 1, 2 }; // explicitly specify class template Pair<int, int> (C++11 onward)
    Pair p2{ 1, 2.5 };           // CTAD used to deduce Pair<int, int> from the initializers (C++17)

    return 0;
}