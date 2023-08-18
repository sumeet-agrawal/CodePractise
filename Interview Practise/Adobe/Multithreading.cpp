#include <iostream>
#include <thread>
#include <mutex>
#include <system_error>

/*class Race_condition
{
public:
    std::mutex mt;
    int n;
    Race_condition() :n(0) {}
    void increment() try {
        //mt.lock();
        std::lock_guard<std::mutex> lock(mt);
        ++n;
        //mt.unlock();
    }
    catch (std::system_error& error)
    {
        std::cout << error.what() << "\n";
    }
};

int main()
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

/*int n = 0;
void print() {
    std::cout <<++n<< " "<<std::this_thread::get_id()<<" Critical Data" << std::endl;
}

int main() {
    std::mutex mutex1, mutex2;
    std::thread t1([&mutex1, &mutex2] {
        std::cout << "Acquiring First mutex..." << std::endl;
        mutex1.lock();
        print();

        std::cout << "Acquiring second mutex..." << std::endl;
        mutex2.lock();
        print();

        mutex1.unlock();
        mutex2.unlock();
        });

    std::thread t2([&mutex1, &mutex2] {
        //changing the order of acquiring mutexes to avoid deadlock
        std::cout << "Acquiring First mutex..." << std::endl;
        mutex1.lock();
        print();

        std::cout << "Acquiring Second mutex..." << std::endl;
        mutex2.lock();
        print();

        mutex1.unlock();
        mutex2.unlock();
        });

    t1.join();
    t2.join();
    std::cout << "Program ran succesfully" << std::endl;
    return 0;
}*/

/*std::mutex mutex;
std::condition_variable cv;
bool ready = false;

void print() {
    std::cout << std::this_thread::get_id() <<" Waiting for other thread to signal ready!" << std::endl;
    std::unique_lock<std::mutex> lock(mutex);
    while (!ready) {
        cv.wait(lock);
    }
    std::cout << std::this_thread::get_id() << " thread is executing now...." << std::endl;
}

void execute() {
    std::cout << std::this_thread::get_id() << " Thready is ready to be executed!" << std::endl;
    ready = true;
    cv.notify_all ();
}

int main() {
    std::thread t1(print);
    std::thread t2(print);
    std::thread t3(execute);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}*/

class Atomic_counter
{
public:
    std::atomic<int> n;
    Atomic_counter() :n(0) {}
    void increment() {
        ++n;
    }
};

int main()
{
    Atomic_counter counter;
    std::thread t1([&counter] {
        for (int i = 0; i < 10000; ++i) {
            counter.increment();
        }
        });

    std::thread t2([&counter] {
        for (int i = 0; i < 10000; ++i) {
            counter.increment();
        }
        });

    t1.join();
    t2.join();

    std::cout << counter.n << std::endl;
    return 0;
}