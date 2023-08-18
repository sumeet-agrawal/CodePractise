#include <unordered_map>
#include <unordered_set>

class NotificationService
{
public:
    using Notification = void*;
private:
    std::unordered_map<int, std::unordered_set<Notification>> m_notifications;
public:
    void addNotification(int userId, Notification notification)
    {
        m_notifications[userId].insert(notification);
    }
    void removeNotification(int userId, Notification notification)
    {
        m_notifications[userId].erase(notification);
    }
    std::unordered_set<Notification> getNotification(int userId)
    {
        return m_notifications[userId];
    }
};