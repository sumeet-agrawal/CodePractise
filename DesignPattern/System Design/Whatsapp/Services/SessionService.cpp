#include <unordered_map>

class SessionService
{
public:
    using Session = void*;

private:
    std::unordered_map<int, Session> m_sessions;

public:    
    void addSession(int userId, Session session)
    {
        m_sessions[userId] = session;
    }
    void removeSession(int userId)
    {
        m_sessions.erase(userId);
    }
    Session getSession(int userId)
    {
        return m_sessions[userId];
    }

};