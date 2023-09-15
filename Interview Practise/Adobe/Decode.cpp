#include <iostream>
#include <unordered_set>

using namespace std;

bool decode(string_view word, string_view code)
{
    unordered_set<char> st;
    for(auto x: word)
        st.insert(x);
    for(auto x: code)
        st.erase(x);
    string str{};
    for(auto x: word)
        if(!st.count(x))
            str+=x;
    return str == code;
}

int main()
{
    string word{"acheranobylkl"};
    string code{"chernobyl"};
    if(decode(word, code))
        cout<<"Decodable\n";
    else
        cout<<"Non decodable\n";
    return 0;
}