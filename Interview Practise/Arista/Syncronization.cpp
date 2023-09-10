#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

using namespace std;

queue<int> buffer;
mutex mtx, print_mtx;
condition_variable cv;

void print(string_view str)
{
    lock_guard<mutex> lg(print_mtx);
    cout<<str<<"\n";
}

void producer()
{
    int index =0;
    while(index<15)
    {
        unique_lock<mutex> lock(mtx);
        if(buffer.size() >= 5)
            cv.wait(lock, [](){ return !(buffer.size() >= 5);});
        buffer.push(index);
        lock.unlock();
        cv.notify_one();
        this_thread::sleep_for(chrono::milliseconds(100));
        print(" Producer produced " + to_string(index));
		index++;
    }
}

void consumer()
{
    while(true)
    {
        unique_lock<mutex> lock(mtx);
        if(buffer.empty())
            cv.wait(lock, [](){ return !buffer.empty();});
        lock.unlock();
        int el = buffer.front();
        buffer.pop();
        cv.notify_one();
        this_thread::sleep_for(chrono::milliseconds(1000));
        print(" Consumer consumed " + to_string(el));
    }    
}

int main()
{
    vector<thread> threads;
    threads.emplace_back(&producer);
    threads.emplace_back(&consumer);
    
    for(auto &x: threads)
        x.join();

    return 0;
}