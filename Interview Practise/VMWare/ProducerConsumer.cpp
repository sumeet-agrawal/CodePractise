#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

using namespace std;

class Resource
{
private:
    bool dataProduced{};
    mutex mtx;
    condition_variable cv;
public:
    Resource() = default;
    void producer()
    {
        cout<<"Data producing\n";
        lock_guard<mutex> lck(mtx);
        this_thread::sleep_for(chrono::milliseconds(2000));
        dataProduced = true;
        cout<<"Data produced\n";
        cv.notify_one();
    }
    void consumer()
    {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [&](){ return dataProduced;});
        cout<<"Data Consumed\n";
    }
};

int main()
{
    vector<thread> threads;
    Resource res;
    threads.push_back(thread{&Resource::producer, &res});
    threads.push_back(thread{&Resource::consumer, &res});
    for(auto &x: threads)
        x.join();
    return 0;
}