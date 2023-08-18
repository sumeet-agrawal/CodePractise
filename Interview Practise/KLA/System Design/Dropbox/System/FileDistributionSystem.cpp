#include "../Component/DataCenter.hpp"

#include <unordered_map>

class FileDistributionSystem
{
private:
    std::unordered_map<int, DataCenter> m_dataCenters;
public:
    void addDataCenter(const DataCenter& datacenter)
    {
        m_dataCenters[m_dataCenters.size()] = datacenter;
    }
    void distributeFile(int key, Version value)
    {
        for(auto &x: m_dataCenters)
            x.second.storeData(key, value);
    }
    Version accessFile(int key)
    {
        for(auto &x: m_dataCenters)
            return x.second.retrieveData(key);
    }
};