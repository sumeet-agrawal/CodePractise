#include <iostream>
#include <vector>
#include <algorithm>

class App
{
public:
	int id;
	int res;
	friend std::ostream& operator<<(std::ostream& out, const App& a)
	{
		out << "[" << a.id << ", " << a.res << "]";
		return out;
	}
};

int main()
{
	std::vector<App> fg{ {4,10}, {1,3}, {3,7},{2,5} };
	std::vector<App> bg{ {1,2}, {2,3}, {3,4}, {4,5} };
	std::sort(fg.begin(), fg.end(), [](const App& a, const App& b) {return a.res < b.res; });
	std::sort(bg.begin(), bg.end(), [](const App& a, const App& b) {return a.res > b.res; });

	int cap{ 10 }, max{ 0 };
	std::vector<App> ans_ind;
	int i{ 0 }, j{ 0 };
	while ((i < fg.size()) && (j < bg.size()))
	{
		int res = fg[i].res + bg[j].res;
		if (res > cap)
		{
			j++;
			continue;
		}
		else
		{
			i++;
			if (res < max)
				continue;
			else if (res > max)
			{
				max = res;
				ans_ind.clear();
			}
			ans_ind.push_back(App(fg[i - 1].id, bg[j].id));
		}
	}
	for (auto& p : ans_ind)
	{
		std::cout << p << " ";
	}
	return 0;
}