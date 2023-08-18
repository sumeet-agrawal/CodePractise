#ifndef DROPBOX_DATA_CENTER
#define DROPBOX_DATA_CENTER

#include "../Entity/File/Version.hpp"

#include <string>
#include <unordered_map>

class DataCenter
{
private:
    int id;
    std::string m_location{};
    std::unordered_map<int, Version> m_data{};
public:
    void storeData(int id, Version value)
    {
        m_data[id] = value;
    }
    Version& retrieveData(int id)
    {
        return m_data[id];
    }
    void updateDataFromOtherCenters(int fileid, std::unordered_map<int, DataCenter>& dataCenters)
    {
        for(auto &x: dataCenters)
            if(id != x.first)
                m_data[id] = x.second.retrieveData(id);
    }
};

#endif