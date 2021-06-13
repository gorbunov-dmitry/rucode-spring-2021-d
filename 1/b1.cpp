#include <algorithm>
#include <iostream>
#include <deque>

int main()
{
	std::cin.tie(nullptr);
	std::cin.sync_with_stdio(false);

	int n;
	std::cin >> n;

	int k;
	std::cin >> k;

	std::deque<int> a(k);
	for (size_t i = 0; i < k; i++)
	{
		std::cin >> a[i];
	}

	std::cout << *std::min_element(a.begin(), a.end()) << '\n';

	for (size_t i = k; i < n; i++)
	{
		a.pop_front();
		int foo;
		std::cin >> foo;
		a.push_back(foo);
		std::cout << *std::min_element(a.begin(), a.end()) << '\n';
	}

	return 0;
}
