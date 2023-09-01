#include <iostream>

class BrowserCore
{
private:
    static BrowserCore* instance;
    BrowserCore()   {}
public:
    static BrowserCore* getInstance()
    {
        if(!instance)
            instance = new BrowserCore();
        return instance;
    }
    BrowserCore() = default;
    BrowserCore(BrowserCore& bc) = delete;
    BrowserCore& operator=(const BrowserCore& bc) = delete;
    void print()
    {
        std::cout<<"Hello World\n";
    }
};

template<typename T>
int add(T a, T b)   {}

int add(int a, int b)   {}

int main()
{
    BrowserCore::getInstance()->print();
    int a = add<int>(1, 1);
    float b = add(1, 2);
    return 0;
}