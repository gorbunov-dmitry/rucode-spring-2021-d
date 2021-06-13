#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <vector>

template <class T>
std::istream& operator >> (std::istream& is, std::vector<T>& v)
{
	for (auto& i : v)
	{
		is >> i;
	}
	return is;
}

template <class T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
	for (auto i : v)
	{
		os << i << ' ';
	}
	return os;
}

int main()
{
	std::cin.tie(nullptr);
	std::cin.sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::vector<long long> a(n);
	std::cin >> a;

	std::vector<long long> dp(n + 1, LLONG_MIN);
	dp[0] = LLONG_MAX;

	std::vector<size_t> e(n + 1, -1);
	std::vector<size_t> p(n, -1);

	for (auto i = a.begin(); i < a.end(); i++)
	{
		auto j = std::upper_bound(dp.begin(), dp.end(), *i, std::greater<long long>());
		if (*i > *j)
		{
			*j = *i;
			size_t dp_index = j - dp.begin();
			size_t a_index = i - a.begin();
			e[dp_index] = a_index;
			p[a_index] = e[dp_index - 1];
		}
	}

	size_t length = n;
	size_t last_index = e[n];
	for (auto i = dp.begin(); i < dp.end(); i++)
	{
		if (*i == LLONG_MIN)
		{
			length = i - dp.begin() - 1;
			last_index = e[i - dp.begin() - 1];
			break;
		}
	}

	std::cout << length << '\n';

	std::stack<size_t> indexes;

	while (last_index != -1)
	{
		indexes.push(last_index + 1);
		last_index = p[last_index];
	}

	while (!indexes.empty())
	{
		std::cout << indexes.top() << '\n';
		indexes.pop();
	}

	return 0;
}
