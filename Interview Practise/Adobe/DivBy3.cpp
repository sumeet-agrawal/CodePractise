#include <iostream>

using namespace std;

bool isDivBy3(string_view str)
{
    int state{};
    for(auto x: str)
    {
        switch (state)
        {
        case 0:
            if(x-'0')   state = 1;
            else        state = 0;
            break;
        case 1:
            if(x-'0')   state = 0;
            else        state = 2;
            break;
        case 2:
            if(x-'0')   state = 2;
            else        state = 1;
        }
    }
    return !state;
}

int main()
{
    string str{"10101"};
    if(isDivBy3(str))
        cout<<"Divisble by 3\n";
    else
        cout<<"Not divisble by 3\n";
    return 0;
}