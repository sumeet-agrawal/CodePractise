#include <iostream>
#include <vector>
#include <algorithm>

struct student
{
    std::string name{};
    int grade{};
};

int main()
{
    std::cout<<"Number of students : ";
    int n{};
    std::cin>>n;
    std::vector<student> vec(n);
    for(int i{};i<n;i++)
        std::cin>>vec[i].name>>vec[i].grade;
    
    std::sort(vec.begin(), vec.end(), [](const student &a, const student &b){
        return a.grade > b.grade;
    });

    for(const auto &x: vec)
        std::cout<<x.name<<" got a grade of "<<x.grade<<"\n";

    return 0;
}