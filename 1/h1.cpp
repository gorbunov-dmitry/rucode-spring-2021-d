#include <algorithm>
#include <iostream>
#include <numeric>
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

int main()
{
	std::cin.tie(nullptr);
	std::cin.sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::vector<int> books(n);
	std::cin >> books;

	std::vector<int> max_pages(n - 1);
	std::cin >> max_pages;

	std::vector<int> permutation(n);
	std::iota(permutation.begin(), permutation.end(), 0);

	int good_permutations_count = 0;

	do
	{
		bool permutation_is_ok = true;
		for (size_t i = 0; i < permutation.size() - 1; i++)
		{
			int prev = permutation[i];
			int next = permutation[i + 1];
			if (books[prev] + books[next] > max_pages[i])
			{
				permutation_is_ok = false;
				break;
			}
		}
		if (permutation_is_ok)
		{
			++good_permutations_count;
		}
	} while (std::next_permutation(permutation.begin(), permutation.end()));

	std::cout << good_permutations_count << '\n';

	return 0;
}
