#include <iostream>
#include <vector>

size_t n, m, k;
std::vector<int> dsu, sz;
std::vector<std::pair<int, std::pair<int, int>>> queries;

void build()
{
    dsu.resize(n);
    sz.resize(n, 1);
    for (size_t i = 0; i < n; i++)
    {
        dsu[i] = i;
    }
}

int find(int x)
{
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
    {
        return;
    }
    if (sz[x] < sz[y])
    {
        std::swap(x, y);
    }
    dsu[y] = x;
    sz[x] += sz[y];
}

int main()
{
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    
    std::cin >> n >> m >> k;
    build();
    
    for (size_t i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
    }
    for (size_t i = 0; i < k; i++)
    {
        std::string type;
        int u, v;
        std::cin >> type >> u >> v;
        u--;
        v--;
        if (type == "cut")
        {
            queries.push_back({ 0, {u, v} });
        }
        else
        {
            queries.push_back({ 1, {u, v} });
        }
    }
    std::vector<bool> ans;
    for (int i = k - 1; i >= 0; i--)
    {
        int u = queries[i].second.first, v = queries[i].second.second;
        if (queries[i].first == 0)
        {
            unite(u, v);
        }
        else
        {
            u = find(u);
            v = find(v);
            if (u == v)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
    }
    for (int i = (int)ans.size() - 1; i >= 0; i--)
    {
        std::cout << (ans[i] ? "YES" : "NO") << '\n';
    }
    return 0;
}
