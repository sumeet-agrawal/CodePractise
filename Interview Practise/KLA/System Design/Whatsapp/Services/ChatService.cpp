#include "../Models/Message.hpp"

#include <unordered_map>
#include <vector>

class ChatService
{
private:
    std::unordered_map<int, std::vector<Message>> m_messages;
public:
    void addMessage(int chatId, Message message)
    {
        m_messages[chatId].push_back(message);
    }
    std::vector<Message> getMessage(int chatId)
    {
        return m_messages[chatId];
    }
};