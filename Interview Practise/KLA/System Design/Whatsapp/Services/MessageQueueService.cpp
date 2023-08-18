#include "../Models/Message.hpp"
#include "../Models/User.hpp"

#include <queue>
#include <unordered_map>

class MessageQueue
{
private:
    std::queue<Message> m_q;
public:
    void enqueMessage(Message message)
    {
        m_q.push(message);
    }
    Message dequeMessage()
    {
        Message message = m_q.front();
        m_q.pop();
        return message;
    }
};

class MessageRouter
{
private:
    std::unordered_map<User, MessageQueue> m_routes;
public:
    void addRoute(User receiver, MessageQueue q)
    {
        m_routes[receiver] = q;
    }
    void routeMessage(User receiever, Message msg)
    {
        m_routes[receiever].enqueMessage(msg);
    }
};