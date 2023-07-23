#ifndef DROPBOX_USER_PROFILE
#define DROPBOX_USER_PROFILE

#include <string>

class Profile
{
private:
    std::string m_bio{};
    std::string m_profilePic{};
public:
    Profile(std::string_view bio={}, std::string_view pic={})
        : m_bio{bio}
        , m_profilePic{pic}
    {}
    void updateBio(std::string_view bio) { m_bio = bio;}
    void updateProfilePic(std::string_view pic) { m_profilePic = pic;}
    Profile& getProfile() { return *this;}
};

#endif