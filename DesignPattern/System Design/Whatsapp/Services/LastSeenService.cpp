#include <unordered_map>

class LastSeenService
{
public:
    using TimeStamp = void*;
private:
    std::unordered_map<int, TimeStamp> m_lastSeen;
public:
    void updateLastSeen(int userId, TimeStamp time)
    {
        m_lastSeen[userId] = time;
    }
    TimeStamp getLastSeen(int userId)
    {
        return m_lastSeen[userId];
    }
};