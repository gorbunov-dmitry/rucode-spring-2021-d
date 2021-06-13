#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

long long dot
(
	const std::pair<long long, long long>& a,
	const std::pair<long long, long long>& b
)
{
	return a.first * b.first + a.second * b.second;
}

long double distance
(
	const std::pair<long long, long long>& a,
	const std::pair<long long, long long>& b
)
{
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

long double distance
(
	const std::pair<long long, long long>& p,
	const std::pair<long long, long long>& a,
	const std::pair<long long, long long>& b
)
{
	std::pair<long long, long long> ab(b.first - a.first, b.second - a.second);
	std::pair<long long, long long> ba(a.first - b.first, a.second - b.second);
	std::pair<long long, long long> ap(p.first - a.first, p.second - a.second);
	std::pair<long long, long long> bp(p.first - b.first, p.second - b.second);

	long double result;

	if (dot(ap, ab) <= 0)
	{
		result = distance(p, a);
	}
	else if (dot(bp, ba) <= 0)
	{
		result = distance(p, b);
	}
	else
	{
		long long dx_p_b = b.first - p.first;
		long long dy_p_b = b.second - p.second;
		long long dx_p_a = a.first - p.first;
		long long dy_p_a = a.second - p.second;
		result = (abs(dy_p_b * dx_p_a - dx_p_b * dy_p_a)) / distance(a, b);
	}
	
	return result;
}

long long area
(
	const std::pair<long long, long long>& a, 
	const std::pair<long long, long long>& b, 
	const std::pair<long long, long long>& c
) 
{
	return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}

inline bool intersects(int a, int b, int c, int d)
{
	if (a > b)
	{
		std::swap(a, b);
	}
	if (c > d)
	{
		std::swap(c, d);
	}
	return std::max(a, c) <= std::min(b, d);
}

bool intersects
(
	const std::pair<long long, long long>& a, 
	const std::pair<long long, long long>& b, 
	const std::pair<long long, long long>& c, 
	const std::pair<long long, long long>& d
) 
{
	return intersects(a.first, b.first, c.first, d.first)
		&& intersects(a.second, b.second, c.second, d.second)
		&& area(a, b, c) * area(a, b, d) <= 0
		&& area(c, d, a) * area(c, d, b) <= 0;
}

int main()
{
	std::pair<long long, long long> a;
	std::pair<long long, long long> b;
	std::pair<long long, long long> c;
	std::pair<long long, long long> d;
	std::cin >>
		a.first >> a.second >>
		b.first >> b.second >>
		c.first >> c.second >>
		d.first >> d.second;

	long double result = 0;
	if (intersects(a, b, c, d))
	{
		result = 0;
	}
	else
	{
		long double d1 = distance(a, c, d);
		long double d2 = distance(b, c, d);
		long double d3 = distance(c, a, b);
		long double d4 = distance(d, a, b);
		auto a = { d1, d2, d3, d4 };
		result = *std::min_element(a.begin(), a.end());
	}

	std::cout << std::fixed << std::setprecision(10) << result << '\n';

	return 0;
}
