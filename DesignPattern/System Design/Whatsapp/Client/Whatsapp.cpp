#include "../Models/Chat.hpp"
#include "../Models/Message.hpp"
#include "../Models/User.hpp"

#include <iostream>
#include <unordered_map>

class Whatsapp
{
private:
    User m_user;
    std::unordered_map<int, User> m_friends;
    std::unordered_map<std::string_view, Chat> m_chats;
    std::queue<Chat> m_unread;
public:
    User createUser(std::string_view name) 
    { 
        User user{name};
        m_friends[user.getId()] = user;
        return user;
    }
    Chat createGroup(std::string_view name, std::vector<User> users)
    {
        Chat chat{name, users};
        m_chats[chat.getName()] = chat;
        return chat;
    }
    void sendMessage(std::string_view sender, std::string_view chatName, 
                    void* content, Message::Type type = Message::text)
    {
        if(!m_chats.contains(chatName))
        {
            std::cout<<"Chat "<<chatName<<" does not exists\n";
            return;
        }
        Chat chat = m_chats[chatName];
        Message msg{sender, content, type};
        //encryptMessage(msg);
        for(auto &x: chat.getUsers())
            if(x.isOnline())
                chat.receiveMessage(msg);
            else
                chat.receiveMessageQueue(msg);
    }
    void updateUserStatus(User user, User::Status status)
    {
        user.setStatus(status);
    }
    void syncMessages()
    {
        while(!m_unread.empty())
        {
            auto t = m_unread.front();
            auto msgs = t.getMessages();
            while(!msgs.empty())
                t.receiveMessage(msgs.front()),
                msgs.pop();
            m_unread.pop();
        }
    }
};