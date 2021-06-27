#include <iostream>
#include <random>
#include <ctime>
#include <unordered_map>

class Random
{
public:
	int getRandom(int min, int max) const
	{
		static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
		return std::uniform_int_distribution{ min, max }(mt);
	}

	std::string getRandomString7() const
	{
		static std::string s{ "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
		int n1 = getRandom(0, 3521614);
		int n2 = getRandom(0, 606207);
		long long n = (long long)n1 * 1000000 + n2;
		std::string rand{};
		while (n)
		{
			rand += s[n % 62];
			n /= 62;
		}
		return rand;
	}
};

class Database
{
private:
	std::unordered_map<std::string, std::string> map{};
	static Database* m_instance;
	Database() {}
public:
	Database(const Database&) = delete;
	void operator=(const Database&) = delete;

	~Database() {}
	static Database* getInstance()
	{
		if (!m_instance)
			m_instance = new Database();
		return m_instance;
	}
	bool add(const std::string&& tiny, const std::string& large)
	{
		std::cout << tiny << "\n";
		if (map.find(tiny) == map.cend())
		{
			map.insert({ tiny, large });
			return true;
		}
		return false;
	}

	std::string get(const std::string& tiny)
	{
		auto ptr = map.find(tiny);
		if (ptr != map.cend())
			return map[tiny];
		return "";
	}
	void printEntry(const std::string& str)
	{
		std::cout << "Total entries: " << map.size() << "\n";
		std::cout << map[str] << "\n";
	}
};

Database* Database::m_instance = nullptr;

int main()
{
	Random r;
	Database* db = Database::getInstance();
	for (int i{ 0 }; i < 10; i++)
	{
		std::string large{};
		for (int j{ 0 }; j < 5; j++)
		{
			large += r.getRandomString7();
		}
		db->add(r.getRandomString7(), large);
	}

	std::string str{};
	std::cin >> str;
	db->printEntry(str);

	return 0;
}