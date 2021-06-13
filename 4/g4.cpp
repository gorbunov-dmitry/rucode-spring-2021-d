#include <iostream>
#include <vector>

int pow(int a, int b, int mod)
{
	int result = 1;
	while (b)
	{
		if (b & 1)
		{
			result = int(result * 1ll * a % mod);
			--b;
		}
		else
		{
			a = int(a * 1ll * a % mod);
			b >>= 1;
		}
	}
	return result;
}

int generator(int p)
{
	std::vector<int> fact;

	int phi = p - 1;
	int n = phi;

	for (int i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			fact.push_back(i);
			while (n % i == 0)
			{
				n /= i;
			}
		}
	}
	if (n > 1)
	{
		fact.push_back(n);
	}

	for (int res = 2; res <= p; ++res)
	{
		bool ok = true;
		for (size_t i = 0; i < fact.size() && ok; ++i)
		{
			ok &= pow(res, phi / fact[i], p) != 1;
		}
		if (ok)
		{
			return res;
		}
	}
	return -1;
}

int main()
{
	std::cin.tie(nullptr);
	std::cin.sync_with_stdio(false);

	int p;

	while (std::cin >> p)
	{
		int result = (p == 2) ? 1 : generator(p);
		std::cout << result << '\n';
	}

	return 0;
}
