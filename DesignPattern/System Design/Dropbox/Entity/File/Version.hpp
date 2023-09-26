#ifndef DROPBOX_FILE_VERSION
#define DROPBOX_FILE_VERSION

#include "../User/User.hpp"

#include <string>

class Version
{
private:
    int m_version{};
    void* m_content{};
public:
    Version(int version={}, void* content={})
        : m_version{version}
        , m_content{content}
    {}
    ~Version()
    {
        delete m_content;
    }
    void* getContent() {  return m_content;}
    int getVersion() { return m_version;}
};

class Annotation
{
private:
    User& m_user;
    std::string m_content{};
public:
    Annotation(User& user, std::string_view content)
        : m_user{user}
        , m_content{content}
    {}
    Annotation(const Annotation& a) = default;
    Annotation operator=(const Annotation& a)
    {
        m_content = a.m_content;
        m_user = a.m_user;
        return *this;
    }
};

class Comment
{
private:
    User& m_user;
    std::string m_message{};
public: 
    Comment(User& user, std::string_view cmt)
        : m_user{user}
        , m_message{cmt}
    {}
    Comment(const Comment& c) = default;
    Comment operator=(const Comment& c)
    {
        m_message = c.m_message;
        m_user = c.m_user;
        return *this;
    }

};

#endif