#ifndef IOBSERVER
#define IOBSERVER

#include <string>

class IObserver
{
public:
    virtual ~IObserver(){}
    virtual void Update(std::string_view) = 0;
};

#endif