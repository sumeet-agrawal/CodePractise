#include "../../Entity/User/User.hpp"

#include <unordered_map>

class AuthManager
{
private:
    std::unordered_map<std::string_view, User> m_users{};
public:
    enum AuthenticateResult
    {
        user_not_exists,
        auth_passed,
        auth_failed,
        pasword_updated
    };
    void registerUser(std::string_view name, std::string_view pwd)
    {
        m_users[name] = {name, pwd};
    }
    AuthenticateResult authenticate(std::string_view name, std::string_view pwd)
    {
        if(!m_users.contains(name))
            return user_not_exists;
        if(m_users[name] == User{name, pwd})
            return auth_passed;
        return auth_failed;
    }
    AuthenticateResult updatePassword(std::string_view name, std::string_view oldPwd, std::string_view newPwd)
    {
        auto result = authenticate(name, oldPwd);
        if( result != auth_passed)
            return result;
        m_users[name].updatePassword(newPwd);
        return pasword_updated;
    }
};

