#include <iostream>
#include <stack>
#include <vector>

void printLeaders(std::vector<int>& arr)
{
    std::stack<int> st{};
    for(auto &x: arr)
    {
        while(!st.empty() && st.top()<x)
            st.pop();
        st.push(x);
    }
    while(!st.empty())
        std::cout<<st.top()<<" ",
        st.pop();
}

int main()
{
    std::vector<int> arr{ 16, 17, 4, 3, 5, 2 };
    printLeaders(arr);
    return 0;
}