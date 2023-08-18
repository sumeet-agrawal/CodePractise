#ifndef DROPBOX_FILE
#define DROPBOX_FILE

#include "../User/User.hpp"
#include "Version.hpp"

#include <memory>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>

class File
{
public:
    enum AccessLevel
    {
        read_only,
        write_only,
        read_write
    };
private:
    std::string m_name{};
    void* m_content{};
    std::vector<Version> m_versions{};
    std::map<std::reference_wrapper<const User>, AccessLevel> m_sharedWith{};
    std::unordered_map<int, Comment> m_comments;
    std::unordered_map<int, Annotation> m_annotations; 
public:
    File(std::string_view name={}, void* content={})
        : m_name{name}
        , m_content{content}
    {}
    ~File()
    {
        delete m_content;
    }
    void shareWithUser(const User& user, AccessLevel access)
    {
        m_sharedWith[user] = access;
    }

    void unShareWithUser(const User& user)
    {
        m_sharedWith.erase(user);
    }

    AccessLevel getAccessLevel(const User& user)
    {
        return m_sharedWith[user];
    }

    void uploadNewFile(const File& file)
    {
        m_versions.push_back({m_versions.size(), file.m_content});
    }
    File getVersionFile(int version)
    {
        m_content = m_versions[binary(0, m_versions.size()-1, version)].getContent();
        return *this;
    }
    int binary(int begin, int end, int version)
    {
        while(begin<=end)
        {
            int mid{(begin+end)/2};
            if(m_versions[mid].getVersion()==version)
                return mid;
            else if(m_versions[mid].getVersion()<version)
                begin = mid+1;
            else
                end = mid -1;
        }
        return -1;
    }
    int getLatestVersion() { return m_versions.rend()->getVersion();}

    void addComment(int id, std::string_view cmt, User& user) { m_comments[id] = {user, cmt};}
    void deleteComment(int id) { m_comments.erase(id);}
    void addAnnotation(int id, std::string_view content, User& user) { m_annotations[id] = {user, content};}
    void deleteAnnotation(int id) { m_annotations.erase(id);}

    std::unordered_map<int, Comment> getComments() { return m_comments;}
    std::unordered_map<int, Annotation> getAnnotation() { return m_annotations;}
};


#endif