#include "../../Entity/File/File.hpp"

#include <algorithm>
#include <unordered_map>
#include <vector>

class VersioningSystem
{
private:
    std::unordered_map<int, File> m_files;
public:
    void uploadFile(int id, const File& file)
    {
        m_files[id].uploadNewFile(file);
    }
    
    File& downloadFileVersion(int id, int version)
    {
        m_files[id].getVersionFile(version);
    }
    int getLatestFileVersion(int id)
    {
        return m_files[id].getLatestVersion();
    }
    void deleteFileVersions(int id)
    {
        m_files.erase(id);
    }
    File& getFile(int id)
    {
        return m_files[id];
    }
};