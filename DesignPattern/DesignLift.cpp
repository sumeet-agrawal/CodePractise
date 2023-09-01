#include <iostream>
#include <set>
#include <thread>
#include <mutex>
#include <random>
#include <chrono>
#include <condition_variable>

const int top = 17;
const int bottom = -3;

class Elevator
{
public:
	enum class Direction
	{
		UP,
		DOWN,
		STAND
	};
	void pressFrom(int floor, Direction d)
	{
		std::unique_lock<std::mutex> lock(mt);
		std::cout << std::this_thread::get_id() << " Request from " << floor << " to go " << (d == Direction::UP ? "up" : "down") << "\n";
		if (floor == top && d == Direction::UP)
		{
			std::cout << std::this_thread::get_id() << " Unable to go up, you are on top most floor\n";
			return;
		}
		else if (floor == bottom && d == Direction::DOWN)
		{
			std::cout << std::this_thread::get_id() << " Unable to go down, you are on bottom most floor\n";
			return;
		}
		switch (d)
		{
		case Direction::UP: up.insert(floor);
			break;
		case Direction::DOWN: down.insert(floor);
			break;
		}
		isPressed = true;
		cv.notify_all();
	}
	void pressTo(int floor)
	{

	}
	void move()
	{
		while (1)
		{
			if (dir == Direction::STAND)
			{
				if (!up.empty())
				{
					dir = Direction::UP;
					moveToFloor(*up.begin());
				}
				else if (!down.empty())
				{
					dir = Direction::DOWN;
					moveToFloor(*down.begin());
				}
				else
				{
					std::unique_lock<std::mutex> lock(mt);
					cv.wait(lock);
				}
			}

		}
	}
	void moveToFloor(int floor)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(std::abs(cur_floor - floor) * 1000));
		std::cout << std::this_thread::get_id() << " Arrived on floor " << floor << ". Going " << (dir == Direction::UP ? "up" : "down") << "\n";
		cur_floor = floor;
		switch (dir)
		{
		case Direction::UP:
			up.erase(up.begin());
			if (!up.empty())
			{
				moveToFloor(*up.begin());
			}
			else if (!down.empty())
			{
				std::cout << "Reached top most pressed. Going down\n";
				dir = Direction::DOWN;
				moveToFloor(*down.begin());
			}
			else
			{
				std::cout << "No more pressed event, Stand\n";
				dir = Direction::STAND;
				isPressed = false;
			}
			break;
		case Direction::DOWN:
			down.erase(down.begin());
			if (!down.empty())
			{
				moveToFloor(*down.begin());
			}
			else if (!up.empty())
			{
				std::cout << "Reached bottom most pressed. Going up\n";
				dir = Direction::UP;
				moveToFloor(*up.begin());
			}
			else
			{
				std::cout << "No more pressed event, Stand\n";
				dir = Direction::STAND;
				isPressed = false;

			}
			break;
		}
	}
	Elevator(int cap, int min, int max)
		: capacity(cap)
		, min_floor(min)
		, max_floor(max)
	{}
private:
	std::mutex mt;
	std::condition_variable cv;
	int capacity{ 0 };

	int min_floor{};
	int max_floor{};
	int cur_floor{ 0 };

	bool isPressed{ false };
	Direction dir{ Direction::STAND };
	std::set<int, std::less<int> > up{};
	std::set<int, std::greater<int>> down{};
};

int getRandom(int min = bottom, int max = top)
{
	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	return std::uniform_int_distribution{ min, max }(mt);
}
int main()
{
	Elevator lift{ 10, bottom, top };
	std::thread elv([&lift]() {
		lift.move();
		});
	std::thread t1([&lift]() {
		for (int i{ 0 }; i < 10; i++)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			lift.pressFrom(getRandom(), static_cast<Elevator::Direction>(getRandom(0, 1)));
		}
		});
	std::thread t2([&lift]() {
		for (int i{ 0 }; i < 10; i++)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			lift.pressFrom(getRandom(), static_cast<Elevator::Direction>(getRandom(0, 1)));
		}
		});
	std::thread t3([&lift]() {
		for (int i{ 0 }; i < 10; i++)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(2500));
			lift.pressFrom(getRandom(), static_cast<Elevator::Direction>(getRandom(0, 1)));
		}
		});
	std::thread t4([&lift]() {
		for (int i{ 0 }; i < 10; i++)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			lift.pressFrom(getRandom(), static_cast<Elevator::Direction>(getRandom(0, 1)));
		}
		});
	std::thread t5([&lift]() {
		for (int i{ 0 }; i < 10; i++)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(4500));
			lift.pressFrom(getRandom(), static_cast<Elevator::Direction>(getRandom(0, 1)));
		}
		});
	t5.join();
	t4.join();
	t3.join();
	t2.join();
	t1.join();
	elv.join();
	return 0;
}