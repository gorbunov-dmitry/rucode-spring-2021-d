#include <iostream>
#include <vector>

int main()
{
	const size_t MOD = 1e9 + 7;

	size_t n;
	std::cin >> n;

	std::vector<size_t> a(n);
	for (auto& item : a)
	{
		std::cin >> item;
	}

	std::vector<size_t> fact(n + 1);
	fact[0] = 1;
	for (auto i = fact.begin() + 1; i < fact.end(); i++)
	{
		*i = ((*(i - 1) % MOD) * ((i - fact.begin()) % MOD)) % MOD;
	}

	std::vector<bool> used(n + 1);

	size_t result = 0;
	for (size_t i = 0; i < a.size(); i++)
	{
		used[a[i]] = true;
		for (size_t j = 1; j < a[i]; j++)
		{
			if (!used[j])
			{
				result += fact[n - i - 1];
				result %= MOD;
			}
		}
	}

	std::cout << ++result % MOD << '\n';

	return 0;
}
