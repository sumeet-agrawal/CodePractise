#ifndef WHATSAPP_USER
#define WHATSAPP_USER

#include <chrono>
#include <string>
#include <vector>

class User
{
public:
    enum Status
    {
        online,
        offline
    };
    using Settings = void*;
    using Contact = void*;
private:
    std::string m_name{};
    int m_id{};
    Status m_status{};
    static int getUniqueId() 
    {
        static int s_idGenerator{};
        return s_idGenerator++;
    }
    std::string m_password{};
    std::vector<Contact> m_contacts{};
    Settings m_privacySettings{};
    std::string m_encryptionKey{};
public:
    User(std::string_view name, Status status=offline)
        : m_name{name}
        , m_id{getUniqueId()}
        , m_status{status}
    {}
    int getId() const { return m_id;}
    bool isOnline() { return m_status == online;}
    void setStatus(Status status)   { m_status = status;}
    void addContact(Contact contact)    { m_contacts.push_back(contact);}
    void updatePrivacySettings(Settings setting)    { /*m_privacySettings.update(setting);*/}
    bool authenticate(std::string_view name, std::string_view pwd)
    {
        return m_name==name && m_password==pwd;
    }
};

#endif