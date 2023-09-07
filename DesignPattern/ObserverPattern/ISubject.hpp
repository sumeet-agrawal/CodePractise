#ifndef ISUBJECT
#define ISUBJECT

class IObserver;

class ISubject
{
public:
    virtual ~ISubject() {}
    virtual void Notify() = 0;
    virtual void Attach(IObserver*) = 0;
    virtual void Detach(IObserver*) = 0;
};

#endif