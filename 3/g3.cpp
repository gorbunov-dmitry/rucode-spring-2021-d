#include <algorithm>
#include <iostream>
#include <vector>

struct Point
{
	long long x, y;
};

struct Angle
{
	long long a, b;
};

bool operator < (const Angle& p, const Angle& q)
{
	if (p.b == 0 && q.b == 0)
	{
		return p.a < q.a;
	}
	return p.a * 1ll * q.b < p.b * 1ll * q.a;
}

long long sq(Point& a, Point& b, Point& c)
{
	return a.x * 1ll * (b.y - c.y) + b.x * 1ll * (c.y - a.y) + c.x * 1ll * (a.y - b.y);
}

int main()
{
	size_t n, m, k;
	std::cin >> n >> m >> k;
	
	std::vector<Point> points(n);
	int zero_id = 0;
	for (size_t i = 0; i < n; i++)
	{
		std::cin >> points[i].x >> points[i].y;
		if (points[i].x < points[zero_id].x || points[i].x == points[zero_id].x && points[i].y < points[zero_id].y)
		{
			zero_id = i;
		}
	}
	Point zero = points[zero_id];
	rotate(points.begin(), points.begin() + zero_id, points.end());
	points.erase(points.begin());
	--n;

	std::vector<Angle> a(n);
	for (size_t i = 0; i < n; i++)
	{
		a[i].a = points[i].y - zero.y;
		a[i].b = points[i].x - zero.x;
		if (a[i].a == 0)
		{
			a[i].b = a[i].b < 0 ? -1 : 1;
		}
	}

	size_t in_count = 0;

	for (size_t i = 0; i < m; i++)
	{
		Point q;
		std::cin >> q.x >> q.y;
		bool in = false;
		if (q.x >= zero.x)
		{
			if (q.x == zero.x && q.y == zero.y)
			{
				in = true;
			}
			else 
			{
				Angle my = { q.y - zero.y, q.x - zero.x };
				if (my.a == 0)
				{
					my.b = my.b < 0 ? -1 : 1;
				}
				auto it = upper_bound(a.begin(), a.end(), my);
				if (it == a.end() && my.a == a[n - 1].a && my.b == a[n - 1].b)
				{
					it = a.end() - 1;
				}
				if (it != a.end() && it != a.begin())
				{
					int p1 = int(it - a.begin());
					if (sq(points[p1], points[p1 - 1], q) <= 0)
					{
						in = true;
					}
				}
			}
		}
		if (in)
		{
			in_count++;
		}
	}

	if (in_count >= k)
	{
		std::cout << "YES" << '\n';
	}
	else
	{
		std::cout << "NO" << '\n';
	}
}
