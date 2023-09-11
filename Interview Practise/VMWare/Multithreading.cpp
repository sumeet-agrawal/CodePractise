#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

using namespace std;

class Application
{
private:
    bool isDataLoaded{};
    condition_variable cv;
    mutex mtx;
public:
    Application()
        : isDataLoaded{false}
    {}
    void loadData()
    {
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout<<"Loading data\n";
        lock_guard<mutex> grd(mtx);
        isDataLoaded = true;
        cv.notify_one();
    }
    void mainTask()
    {
        cout<<"Do handshake\n";
        unique_lock<mutex> uLock(mtx);
        cv.wait(uLock, [&](){ return isDataLoaded;});
        cout<<"Process loaded data\n";
    }
};

int main()
{
    Application app;
    vector<thread> threads;
    threads.push_back(thread{&Application::loadData, &app});
    threads.push_back(thread{&Application::mainTask, &app});
    for(auto &x: threads)
        x.join();
    return 0;
}