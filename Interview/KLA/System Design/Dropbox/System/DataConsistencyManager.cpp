#include "../Component/DataCenter.hpp"

#include <unordered_map>

class DataConsistencyManager
{
private:
    std::unordered_map<int, DataCenter> m_dataCenters;
public:
    void addDataCenter(const DataCenter& dataCenter)
    {
        m_dataCenters[m_dataCenters.size()] = dataCenter;
    }
    void syncData(int id, Version file)
    {
        for(auto &x: m_dataCenters)
            x.second.storeData(id, file);
    }
    void maintainConsistency(int id)
    {
        for(auto &x: m_dataCenters)
            x.second.updateDataFromOtherCenters(id, m_dataCenters);
    }
};