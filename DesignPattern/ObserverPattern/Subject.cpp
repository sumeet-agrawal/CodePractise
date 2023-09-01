#include "ISubject.hpp"
#include "IObserver.hpp"

#include <iostream>
#include <list>
#include <functional>

using namespace std;

class Subject : public ISubject
{
public:
    virtual ~Subject()  { cout<<"Subject closing\n";  }
    void Attach(IObserver* observer)  override
    {
        observers.push_back(observer);
    }
    void Detach(IObserver* observer)  override
    {
        observers.remove(observer);
    }
    void Notify()  override
    {
        for (auto& observer : observers)
        {
            observer->Update(message);
        }
    }
    void CreateMessage(string_view mes = "Empty")
    { 
        message = mes;
        Notify();
    }
private:
    list<IObserver*> observers;
    string message;
};