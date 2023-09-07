#include "IObserver.hpp"
#include "ISubject.hpp"

#include <string>
#include <iostream>

using namespace std;

class Observer : public IObserver
{
public:
    Observer(ISubject& subject) : m_subject{subject}, m_id{Observer::getID()}
    {
        m_subject.Attach(this);
    }
    void Update(string_view message) override
    {
        m_message = message;
        cout << "Observer " << m_id << ": " << m_message << endl;
    }
    void RemoveMeFromTheList()
    {
        m_subject.Detach(this);
    }
    ~Observer()
    {
        RemoveMeFromTheList();
    }
private:
    static int getID()
    {
        static int id = 0;
        return ++id;
    }
    string m_message;
    ISubject& m_subject;
    int m_id;
};