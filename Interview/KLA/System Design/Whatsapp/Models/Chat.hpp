#ifndef WHATSAPP_CHAT
#define WHATSAPP_CHAT

#include "Message.hpp"
#include "User.hpp"

#include <queue>
#include <vector>

class Chat
{
protected:
    std::string m_name;
    std::vector<User> m_users;
    std::queue<Message> m_messages;
public:
    Chat(std::string_view name={}, std::vector<User> users={})
        : m_name{name}
        , m_users{users}
    {}
    void addUser(User user) { m_users.push_back(user);}
    void receiveMessageQueue(Message message) { m_messages.push(message);}
    void receiveMessage(Message msg) 
    {
        //decryptMessage(msg); 
        std::cout<<"Message received\n";
    }
    std::string_view getName()  { return m_name;}
    std::vector<User> getUsers()    { return m_users;}
    std::queue<Message> getMessages()   { return m_messages;}
};

#endif