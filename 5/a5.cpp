#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

std::vector<int> p;

int dsu_get(int v)
{
	if (p[v] == v)
	{
		return v;
	}
	p[v] = dsu_get(p[v]);
	return p[v];
}

void dsu_unite(int a, int b)
{
	a = dsu_get(a);
	b = dsu_get(b);
	if (rand() & 1)
	{
		std::swap(a, b);
	}
	if (a != b)
	{
		p[a] = b;
	}
}

int main()
{
	std::cin.tie(nullptr);
	std::cin.sync_with_stdio(false);

	size_t n, m;
	std::cin >> n >> m;

	std::vector<std::pair<int, std::pair<int, int>>> g;
	int a, b, w;
	while (std::cin >> a >> b >> w)
	{
		std::pair<int, int> edge = { a - 1, b - 1 };
		g.emplace_back(w, edge);
	}
	std::sort(g.begin(), g.end());

	p.resize(n);
	std::iota(p.begin(), p.end(), 0);
	
	unsigned int result = 0;

	for (size_t i = 0; i < m; i++)
	{
		int a = g[i].second.first;
		int b = g[i].second.second;
		int w = g[i].first;
		if (dsu_get(a) != dsu_get(b))
		{
			result += w;
			dsu_unite(a, b);
		}
	}

	std::cout << result << '\n';

	return 0;
}
