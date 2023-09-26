#include "../../Entity/User/User.hpp"

#include <memory>
#include <unordered_map>
#include <unordered_set>

class ConnectionManager
{
private:
    std::unordered_map<std::reference_wrapper<const User>, std::unordered_set<std::reference_wrapper<const User>>> m_connections;
public:
    void add(const User& user1, const User& user2)
    {
        m_connections[user1].insert(user2);
        m_connections[user2].insert(user1);
    }
    void remove(const User& user1, const User& user2)
    {
        m_connections[user1].erase(user2);
        m_connections[user2].erase(user1);
    }
    std::unordered_set<std::reference_wrapper<const User>>& getConnections(const User& user)
    {
        return m_connections[user];
    }
};