#include <unordered_map>

class ProfileService
{
public:
    using Profile = void*;
private:
    std::unordered_map<int , Profile> m_profiles;
public:
    void addProfile(int userId, Profile profile)
    {
        m_profiles[userId] = profile;
    }
    void updateProfile(int userId, Profile profile)
    {
        m_profiles[userId] = profile;
    }
    Profile getProfile(int userId)
    {
        return m_profiles[userId];
    }
};