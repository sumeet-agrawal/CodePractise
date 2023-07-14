#include <algorithm>
#include <iostream>
#include <vector>

struct StudentGrade 
{
    std::string name{};
    char grade{};
};

class GradeMap
{
    using Vector = std::vector<StudentGrade>;
    using Itr = std::vector<StudentGrade>::iterator;
public:
    char& operator[](const std::string &str)
    {
        auto pos{binarySearch(0, m_map.size()-1, str)};
        if(pos != -1)
            return m_map[pos].grade;
        m_map.push_back({str});
        int i{};
        for(i=m_map.size()-1;i>0 && m_map[i].name<m_map[i-1].name;--i)
            std::swap(m_map[i], m_map[i-1]);
        
        return m_map[i].grade;
    }
private:
    int binarySearch(int begin, int end, const std::string& val)
    {
        while(begin<=end)
        {
            int mid{(begin+end)>>1};
            if(m_map[mid].name==val)
                return mid;
            else if(m_map[mid].name<val)
                return binarySearch(mid+1, end, val);
            else
                return binarySearch(begin, mid-1, val);
        }
        return -1;
    }
    Vector m_map{};
};

int main()
{
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}