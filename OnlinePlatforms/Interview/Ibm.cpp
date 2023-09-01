#include <iostream>
using namespace std;

class Student
{
private:
    int roll{};
    char* name;
    int size{};
public:
    Student()
    {

    }
    Student(int r, char* str, int s)
        : roll{r}
        , name{str}
        , size{s}
    {}
    Student(const Student& std)
        : roll{std.roll}
        , size{std.size}
    {
        name = new char(size);
        for(int i{};i<size;i++)
            name[i] = std.name[i];
    }
    Student& operator=(const Student& std)
    {
        roll = std.roll;
        size = std.size;
        delete[] name;
        name = new char(size);
        for(int i{};i<size;i++)
            name[i] = std.name[i];
        return *this;
    }
    ~Student()
    {
        delete[] name;
    }
    void print()
    {
        cout<<roll<<" "<<name<<"\n";
    }
    Student& getDetails()   { return *this;}
};

class StudentDB
{
    vecto<Student> list;
    public:
    getDetails
};



int main()
{
    Student s({1, "Sumeet", 6});
    Student* st = new Student();
    if(!st)
    Student t = s;
    t.print();
    return 0;
}