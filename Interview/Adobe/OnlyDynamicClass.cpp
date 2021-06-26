#include <iostream>

class Dynamic
{
private:
	~Dynamic() { std::cout << "Destructor\n"; }
public:
	Dynamic() { std::cout << "Constructor\n"; }
	friend void deallocate(Dynamic* d);
};

void deallocate(Dynamic* d)
{
	delete d;
}

int main()
{
	Dynamic* d = new Dynamic();
	deallocate(d);
	return 0;

}