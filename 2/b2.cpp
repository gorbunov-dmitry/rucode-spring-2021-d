#include <iostream>
#include <string>

short n;

void generate_sequences(short position = 0, short balance = 0, std::string result = "")
{
	if (position == n)
	{
		std::cout << result << '\n';
		return;
	}
	if (balance + 1 <= n - position - 1)
	{
		result.push_back('(');
		generate_sequences(position + 1, balance + 1, result);
		result.pop_back();
	}
	if (balance > 0)
	{
		result.push_back(')');
		generate_sequences(position + 1, balance - 1, result);
		result.pop_back();
	}
}

int main()
{
	std::cin >> n;
	n *= 2;
	generate_sequences();
	return 0;
}
