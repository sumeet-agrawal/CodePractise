#ifndef WHATSAPP_MESSAGE
#define WHATSAPP_MESSAGE

#include <string>

class Message
{
public:
    enum Type
    {
        text, 
        image, 
        video, 
        audio,
        contact,
        location
    };
private:
    std::string m_sender;
    void* m_content;
    Type m_type;
public:
    Message(std::string_view name={}, void* content={}, Type type={})
        : m_sender{name}
        , m_content{content}
        , m_type{type}
    {}
};

#endif