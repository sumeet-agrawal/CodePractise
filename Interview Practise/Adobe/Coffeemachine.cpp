#include <iostream>
#include <string>
#include <array>
#include <random>
#include <ctime>
#include <thread>
#include <chrono>

class Resource
{
private:
	double amount{ 0 };
protected:
	Resource(double d)
		: amount(d)
	{}
public:
	double getAmount() const { return amount; }
	void addAmount(double a) { amount += a; }
	void reduceAmount(double a) { amount -= a; }
	virtual void Notify() = 0;
};

class Water : public Resource
{
	//Amount is in liters
public:
	Water(double w)
		: Resource(w)
	{}
	void Notify()
	{
		std::cout << "Water is emptied, please refill it\n";
	}
};

class Milk : public Resource
{
	//Amount in litres
public:
	Milk(double d)
		: Resource(d)
	{}
	void Notify()
	{
		std::cout << "Milk is emptied, please refill it\n";
	}
};

class CoffeeBeans : public Resource
{
	//Amount in kilograms
public:
	CoffeeBeans(double d)
		: Resource(d)
	{}
	void Notify()
	{
		std::cout << "Beans is emptied, please refill it\n";
	}
};

class CoffeeDisplay
{
public:
	enum class Type
	{
		WarmWater,
		WarmMilk,
		Latte,
		Capacino,
		Frapacino,
		Mochacino,
		FilterCoffee,

		max_types
	};
	Type getType() const { return m_type; }
	friend std::ostream& operator<<(std::ostream& out, const CoffeeDisplay& d)
	{
		out << "Coffee Options\n";
		for (int i{ static_cast<int>(Type::WarmWater) }; i < static_cast<int>(Type::max_types); i++)
		{
			out << i + 1 << ". " << d.getString(static_cast<Type>(i)) << "\n";
		}
		return out;
	}
	double getWater(const Type& t) const { return CoffeeTable[static_cast<int>(t)][0]; }
	double getMilk(const Type& t) const { return CoffeeTable[static_cast<int>(t)][1]; }
	double getBeans(const Type& t) const { return CoffeeTable[static_cast<int>(t)][2]; }
	std::string getString(const Type& t) const
	{
		switch (t)
		{
		case Type::WarmWater: return "WarmWater";
		case Type::WarmMilk: return "WarmMilk";
		case Type::Latte: return "Latte";
		case Type::Capacino: return "Capacino";
		case Type::Frapacino: return "Frapacino";
		case Type::Mochacino: return "Mochacino";
		case Type::FilterCoffee: return "FilterCoffee";
		default: return "Wrong Type";
		}
	}
private:
	const double CoffeeTable[static_cast<int>(Type::max_types)][3]{
		{0.15, 0, 0},
		{0, 0.15, 0},
		{0.05,0.1, 0.01},
		{0.07, 0.08, 0.02},
		{0.08, 0.07, 0.03},
		{0.09, 0.06, 0.04},
		{0.03, 0.12, 0.02}
	};
	Type m_type{ Type::Latte };
};

class CoffeeMachine
{
private:
	Water& m_water;
	Milk& m_milk;
	CoffeeBeans& m_beans;
	CoffeeDisplay disp;

	bool canAdd(Resource& rs, double amount)
	{
		if (rs.getAmount() - amount < 0)
		{
			rs.Notify();
			return false;
		}
		else if (rs.getAmount() - amount == 0)
		{
			rs.Notify();
			return true;
		}
		return true;
	}
	bool makeCoffee(const CoffeeDisplay::Type& t)
	{
		if (canAdd(m_water, disp.getWater(t)) && canAdd(m_milk, disp.getMilk(t)) && canAdd(m_beans, disp.getBeans(t)))
		{
			m_water.reduceAmount(disp.getWater(t));
			m_milk.reduceAmount(disp.getMilk(t));
			m_beans.reduceAmount(disp.getBeans(t));
			return true;
		}
		return false;
	}
public:
	CoffeeMachine(Water& wt, Milk& mk, CoffeeBeans& cb)
		: m_water(wt)
		, m_milk(mk)
		, m_beans(cb)
		, disp(CoffeeDisplay())
	{}
	void showOptions()
	{
		std::cout << disp << "\n";
	}
	bool deliverCoffee(const CoffeeDisplay::Type& t)
	{
		std::cout << "You ordered : " << disp.getString(t) << "\n\nWait for some time\n";
		for (int i{ 10 }; i <= 100; i += 10)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << i << " ";
		}
		std::cout << "\n";
		if (makeCoffee(t))
		{
			std::cout << "\nHey!!! Here is your " << disp.getString(t) << ".\n\Enjoy and have a blast!!!\n\n\n";
			std::cout << "(Water:" << m_water.getAmount() << " Milk:" << m_milk.getAmount() << "Beans:" << m_beans.getAmount() << ")\n";
			return true;
		}
		std::cout << "Sorry Resources to make your coffee just Ran Out !!\n Pantry guy will be refilling it shortly\n Inconvenience is deeply regretted\n";
		return false;
	}
};

int RandomCoffeeGenerator(int min, int max)
{
	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	return std::uniform_int_distribution{ min,max }(mt);
}

int main()
{
	Water water{ Water(20.0) };
	Milk milk{ Milk(10.0) };
	CoffeeBeans coffeebeans{ CoffeeBeans(2.0) };

	CoffeeMachine cm{ CoffeeMachine(water, milk, coffeebeans) };

	bool flag = false;
	int min = static_cast<int>(CoffeeDisplay::Type::WarmWater);
	int max = static_cast<int>(CoffeeDisplay::Type::max_types) - 1;

	do {
		cm.showOptions();
		flag = cm.deliverCoffee(static_cast<CoffeeDisplay::Type>(RandomCoffeeGenerator(min, max)));
	} while (flag);

	return 0;
}