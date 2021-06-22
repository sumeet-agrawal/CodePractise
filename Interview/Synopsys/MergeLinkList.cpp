#include <iostream>
#include <list>

std::ostream& operator<<(std::ostream& out, const std::list<int>& li)
{
    for (auto& i : li)
    {
        out << i << " ";
    }
    return out;
}

std::list<int> sortedMerge(const std::list<int>& a, const std::list<int>& b)
{
    std::list<int> res{};
    auto a_i = a.cbegin();
    auto b_i = b.cbegin();
    while (true)
    {
        if (a_i != a.cend())
        {
            if (b_i != b.cend())
            {
                if (*a_i < *b_i)
                {
                    res.push_back(*a_i);
                    ++a_i;
                }
                else if (*a_i > *b_i)
                {
                    res.push_back(*b_i);
                    ++b_i;
                }
                else
                {
                    res.push_back(*a_i);
                    ++a_i;
                    ++b_i;
                }
            }
            else
            {
                res.push_back(*a_i);
                ++a_i;
            }
        }
        else
        {
            if (b_i != b.cend())
            {
                res.push_back(*b_i);
                ++b_i;
            }
            else
            {
                break;
            }
        }
    }
    return res;
}

int main()
{
    /* Start with the empty list */
    std::list<int> res{};
    std::list<int> a{};
    std::list<int> b{};

    /* Let us create two sorted linked lists
    to test the functions
    Created lists, a: 5->10->15, b: 2->3->20 */
    a.push_front(15);
    a.push_front(10);
    a.push_front(5);

    b.push_front(20);
    b.push_front(3);
    b.push_front(2);

    /* Remove duplicates from linked list */
    res = sortedMerge(a, b);

    std::cout << "Merged Linked List is: " << res << "\n";

    return 0;
}