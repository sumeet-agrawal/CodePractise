#include <iostream>

template<typename T>
class Singleton {
public:
    static T& instance()
    {
        static T instance{};
        return instance;
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator= (const Singleton) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

protected:
    Singleton() {}
};


class Test final : public Singleton<Test>
{
    friend class Singleton<Test>;
private:
    Test() { std::cout << "constructed\n"; }
    ~Test() {  std::cout << "destructed\n"; }
public:
    void use() const { std::cout << "in use" << std::endl; };
};

int main()
{
    std::cout << "Entering main()" << std::endl;
    {
        auto const& t = Test::instance();
        t.use();
    }
    {
        auto const& t = Test::instance();
        t.use();
    }
    std::cout << "Leaving main()" << std::endl;
}