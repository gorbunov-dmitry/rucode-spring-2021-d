#include <climits>
#include <iostream>
#include <set>
#include <vector>

int main()
{
	int n, m;
	std::cin >> n >> m;

	int s, t;
	std::cin >> s >> t;
	--s; --t;

	std::vector<std::vector<std::pair<int, int>>> g(n);

	for (size_t i = 0; i < m; i++)
	{
		int x, y, w;
		std::cin >> x >> y >> w;
		--x; --y;
		g[x].push_back({ y, w });
		g[y].push_back({ x, w });
	}

	std::vector<int> d(n, INT_MAX);
	d[s] = 0;

	std::set<std::pair<int, int>> q;
	q.emplace(d[s], s);

	while (!q.empty())
	{
		int v = q.begin()->second;
		q.erase(q.begin());

		for (size_t j = 0; j < g[v].size(); j++)
		{
			int to = g[v][j].first;
			int len = g[v][j].second;
			if (d[v] + len < d[to])
			{
				q.erase({ d[to], to });
				d[to] = d[v] + len;
				q.emplace(d[to], to);
			}
		}
	}

	if (d[t] == INT_MAX)
	{
		std::cout << -1 << '\n';
	}
	else
	{
		std::cout << d[t] << '\n';
	}

	return 0;
}
