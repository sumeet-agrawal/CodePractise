#ifndef DROPBOX_USER
#define DROPBOX_USER

#include "Profile.hpp"
#include <string>

class User
{
private:
    std::string m_name{};
    std::string m_password{};
    Profile m_profile{};
public:
    User(std::string_view name, std::string_view pwd, Profile profile = {})
        : m_name{name}
        , m_password{pwd}
        , m_profile{profile}
    {}
    bool operator==(const User& user)
    {
        return m_name==user.m_name && m_password==user.m_password;
    }
    std::string_view getName() const { return m_name; }
    void updateProfile(const Profile& profile) { m_profile = profile;}
    void updatePassword(std::string_view pwd) { m_password = pwd;}
};

#endif