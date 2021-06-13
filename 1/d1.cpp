#include <iostream>
#include <set>

int main()
{
	std::cin.tie(nullptr);
	std::cin.sync_with_stdio(false);

	std::set<int> free_rooms;
	for (size_t i = 0; i < 200000; i++)
	{
		free_rooms.insert(i + 1);
	}

	int n;
	std::cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		int a;
		std::cin >> a;
		if (a > 0)
		{
			auto it = free_rooms.lower_bound(a);
			std::cout << *it << '\n';
			free_rooms.erase(it);
		}
		else
		{
			free_rooms.insert(-a);
		}
	}

	return 0;
}
