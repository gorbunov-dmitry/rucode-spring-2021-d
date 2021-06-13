#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

template <class T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
	for (const auto& item : v)
	{
		os << item << ' ';
	}
	return os;
}

int main()
{
	std::cin.tie(nullptr);
	std::cin.sync_with_stdio(false);

	int n, k;
	std::cin >> n >> k;

	if (n == 0)
	{
		return 0;
	}

	std::vector<int> p(n);
	std::iota(p.begin(), p.end(), 1);
	
	do
	{
		bool is_permutation_good = true;
		for (auto i = p.begin() + 1; i < p.end(); i++)
		{
			if (abs(*i - *(i - 1)) < k)
			{
				is_permutation_good = false;
				break;
			}
		}
		if (is_permutation_good)
		{
			std::cout << p << '\n';
		}
	} while (std::next_permutation(p.begin(), p.end()));

	return 0;
}
