#include <iostream>
#include <queue>
#include <functional>
#include <vector>

void printMedian(int A[], int size)
{
    std::priority_queue<int, std::vector<int>, std::less<int>> firstHalf{}; //MaxHeap
    std::priority_queue<int, std::vector<int>, std::greater<int>> secondHalf{}; //MinHeap
    int i{ 0 };
    while (i < size)
    {
        if (firstHalf.empty() || A[i] < firstHalf.top())
            firstHalf.push(A[i]);
        else
            secondHalf.push(A[i]);
        std::cout << "Median after inserting " << A[i] << " is ";
        if (firstHalf.size() + 1 < secondHalf.size())
        {
            firstHalf.push(secondHalf.top());
            secondHalf.pop();
        }
        else if (secondHalf.size() + 1 < firstHalf.size())
        {
            secondHalf.push(firstHalf.top());
            firstHalf.pop();
        }

        if (firstHalf.size() == secondHalf.size())
            std::cout << "{" << firstHalf.top() << ", " << secondHalf.top() << "}\n";
        else if (firstHalf.size() < secondHalf.size())
            std::cout << secondHalf.top() << "\n";
        else
            std::cout << firstHalf.top() << "\n";
        i++;
    }
}

int main()
{
    int A[] = { 5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4 };
    int size = sizeof(A) / sizeof(int);

    // In lieu of A, we can also use data read from a stream
    printMedian(A, size);

    return 0;
}