#include <iostream>
#include <queue>

int main()
{
    std::priority_queue<int> maxHeap{};
    std::priority_queue<int, std::vector<int>, std::greater<>> minHeap{};

    std::vector<double> arr{5, 15, 1, 3};

    for(int i{};i<arr.size();i++)
    {
        if(maxHeap.size() <= minHeap.size())
            maxHeap.push(arr[i]);
        else
            minHeap.push(arr[i]);

        if(minHeap.size() && maxHeap.top() > minHeap.top())
        {
            int maxTop = maxHeap.top();
            int minTop = minHeap.top();

            maxHeap.pop(); minHeap.pop();

            maxHeap.push(minTop); minHeap.push(maxTop);
        }

        if(maxHeap.size() > minHeap.size())
            arr[i] = maxHeap.top();
        else
            arr[i] = (maxHeap.top() + minHeap.top())/2.0;
    }

    for(const auto& x: arr)
        std::cout<<x<<" ";
    std::cout<<"\n";

    return 0;
}