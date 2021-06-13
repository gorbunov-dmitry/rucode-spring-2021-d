#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	std::cin.tie(nullptr);
	std::cin.sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::vector<int> left_bound(n);
	std::vector<int> right_bound(n);

	for (size_t i = 0; i < n; i++)
	{
		std::cin >> left_bound[i] >> right_bound[i];
	}

	std::vector<int> combo = left_bound;
	combo.insert(combo.end(), right_bound.begin(), right_bound.end());

	std::sort(combo.begin(), combo.end());
	auto end = std::unique(combo.begin(), combo.end());

	for (size_t i = 0; i < n; i++)
	{
		left_bound[i] = std::lower_bound(combo.begin(), end, left_bound[i]) - combo.begin();
		right_bound[i] = std::lower_bound(combo.begin(), end, right_bound[i]) - combo.begin();
	}

	for (size_t i = 0; i < n; i++)
	{
		std::cout << left_bound[i] << ' ' << right_bound[i] << '\n';
	}

	return 0;
}
