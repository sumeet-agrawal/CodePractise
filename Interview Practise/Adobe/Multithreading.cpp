#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <system_error>
#include <vector>
#include <atomic>

using namespace std;

class Race_condition
{
public:
    std::mutex mt;
    int n;
    Race_condition() :n(0) {}
    void increment() try {
        std::lock_guard<std::mutex> lock(mt);
        ++n;
    }
    catch (std::system_error& error)
    {
        std::cout << error.what() << "\n";
    }
};

/*int main()
{
    Race_condition racer;
    std::thread t1([&racer] {
        for (int i = 0; i < 10000; ++i) {
            racer.increment();
        }
        });
    std::thread t2([&racer] {
        for (int i = 0; i < 10000; ++i) {
            racer.increment();
        }
        });
    t1.join();
    t2.join();

    std::cout << racer.n << std::endl;
    return 0;
}*/

class Atomic_counter
{
public:
    std::atomic<int> n{};
    void increment() {
        ++n;
    }
};

int main()
{
    Atomic_counter counter;
    vector<thread> threads;
    threads.push_back(thread{[&counter] (){
        for (int i = 0; i < 10; ++i) {
            counter.increment();
            cout<<"First thread \n";
        }
    }});
    threads.push_back(thread{[&counter] (){
        for (int i = 0; i < 10; ++i) {
            counter.increment();
            cout<<"Second thread \n";
        }
    }});

    for(auto &x: threads)
        x.join();
    
    std::cout << counter.n << '\n';
    return 0;
}