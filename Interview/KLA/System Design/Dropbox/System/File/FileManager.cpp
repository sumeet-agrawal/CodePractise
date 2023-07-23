#include "../../Entity/File/File.hpp"
#include "VersioningSystem.hpp"

#include <memory>
#include <unordered_map>

class FileManager
{
private:
    VersioningSystem versionSystem;
public:
    void upload(int id, std::string_view name, void* content)
    {
        versionSystem.uploadFile(id, {name, content});
    }
    File& download(int id)
    {
        return versionSystem.downloadFileVersion(id, versionSystem.getLatestFileVersion(id));
    }
    void deleteFile(int id)
    {
        versionSystem.deleteFileVersions(id);
    }
    void createFile(int id, std::string_view name, void* content)
    {
        upload(id, name, content);
    }
    void shareFile(int file_id, const User& user, File::AccessLevel accessLevel = File::read_only)
    {
        findFile(file_id).shareWithUser(user, accessLevel);
    }
    void unShareFile(int file_id, const User& user)
    {
        findFile(file_id).unShareWithUser(user);
    }
    File& findFile(int file_id)
    {
        return versionSystem.getFile(file_id);
    }

    File::AccessLevel getAccessLevel(int id, const User& user)
    {
        return findFile(id).getAccessLevel(user);
    }

    void addComment(int file_id, int c_id, User& user, std::string_view cmt) 
    {
        findFile(file_id).addComment(c_id, cmt, user);
    }
    
};