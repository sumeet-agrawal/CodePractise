#include <iostream>
#include <stack>

typedef unsigned int ui;
ui average(ui a, ui b, ui c, ui d)
{
	ui sumby4{ 0 };
	ui remby4{ 0 };
	sumby4 += a / 4;
	remby4 += a % 4;
	sumby4 += b / 4;
	remby4 += b % 4;
	sumby4 += c / 4;
	remby4 += c % 4;
	sumby4 += d / 4;
	remby4 += d % 4;
	sumby4 += remby4 / 4;
	return sumby4;
	/*std::stack<ui> st;
	ui carry{ 0 };
	while (a || b || c || d || carry)
	{
		ui n = (a % 10) + (b % 10) + (c % 10) + (d % 10) + carry;
		st.push(n % 10);
		carry = n / 10;
		a /= 10; b /= 10; c /= 10; d /= 10;
	}
	carry = 0;
	ui ans{ 0 };
	while (!st.empty())
	{
		ans *= 10;
		ans += ((carry * 10) + st.top()) / 4;
		carry = ((carry * 10) + st.top()) % 4;
		st.pop();
	}
	return ans;*/
}
int main()
{
	ui a, b, c, d;
	std::cin >> a >> b >> c >> d;
	std::cout << average(a, b, c, d) << "\n";

	return 0;
}