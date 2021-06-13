#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

    size_t n;
    std::cin >> n;
    
    std::vector<std::pair<int64_t, int64_t>> positions(n);
    for (auto& position : positions)
    {
        std::cin >> position.first >> position.second;
    }

    std::vector<int64_t> costs(n);
    for (auto& cost : costs)
    {
        std::cin >> cost;
    }
    
    std::vector<int64_t> ks(n);
    for (auto& k : ks)
    {
        std::cin >> k;
    }

    int64_t result = 0;
    std::vector<int64_t> power_plants;
    std::vector<std::pair<int64_t, int64_t>> connections;

    std::vector<bool> used(n);
    std::vector<int64_t> parent(n, -1);
    
    for (int64_t _n = n; _n--;)
    {
        int64_t mi = INT64_MAX;
        int64_t u = -1;
        for (size_t i = 0; i < n; i++)
        {
            if (used[i])
            {
                continue;
            }

            if (costs[i] < mi)
            {
                mi = costs[i];
                u = i;
            }
        }

        result += mi;
        used[u] = true;
        if (parent[u] == -1)
        {
            power_plants.push_back(u);
        }
        else
        {
            connections.emplace_back(std::min(parent[u], u), std::max(parent[u], u));
        }

        for (size_t i = 0; i < n; i++)
        {
            int64_t x_diff = positions[u].first - positions[i].first;
            int64_t y_diff = positions[u].second - positions[i].second;
            int64_t temp = (ks[u] + ks[i]) * (abs(x_diff) + abs(y_diff));
            if (temp < costs[i])
            {
                costs[i] = temp;
                parent[i] = u;
            }
        }
    }

    std::cout << result << '\n';
    std::cout << power_plants.size() << '\n';
    std::sort(power_plants.begin(), power_plants.end());
    for (const auto& power_plant : power_plants)
    {
        std::cout << power_plant + 1 << ' ';
    }
    std::cout << '\n';
    std::cout << connections.size() << '\n';
    for (const auto& connection : connections)
    {
        std::cout << connection.first + 1 << ' ' << connection.second + 1 << '\n';
    }

    return 0;
}
