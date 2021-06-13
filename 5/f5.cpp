#include <iostream>
#include <vector>

const int64_t P = (int64_t) 1e6 + 3;

size_t n, m;
int64_t zerg = 0;
std::vector<std::pair<int64_t, int64_t>> dsu;
std::vector<int64_t> sz;
std::vector<int64_t> read;

void init()
{
    dsu.resize(n);
    sz.resize(n, 1);
    read.resize(n, 0);
    for (size_t i = 0; i < n; i++)
    {
        dsu[i] = { i, 0 };
    }
}

int64_t find(int64_t x)
{
    if (x == dsu[(int)x].first)
    {
        return x;
    }
    int64_t v = find(dsu[(int)x].first);
    dsu[(int)x].second += dsu[(int)dsu[(int)x].first].second;
    if (v == dsu[(int)x].first)
    {
        dsu[(int)x].second -= dsu[(int)v].second;
    }
    dsu[(int)x].first = v;
    return v;
}

void unite(int64_t x, int64_t y)
{
    x = find(x);
    y = find(y);
    
    if (x == y)
    {
        return;
    }
    
    zerg = (13 * zerg + 11) % P;
    
    if (sz[(int)x] < sz[(int)y])
    {
        std::swap(x, y);
    }
    
    dsu[(int)y].second -= dsu[(int)x].second;
    dsu[(int)y].first = x;
    
    sz[(int)x] += sz[(int)y];
}

int main()
{
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    
    std::cin >> n >> m;
    
    init();
    for (size_t i = 0; i < m; i++)
    {
        int type;
        std::cin >> type;

        switch (type)
        {
        case 1:
            int64_t x;
            std::cin >> x;
            
            x = (x + zerg) % n;
            x = find(x);
            
            dsu[(int)x].second++;
            zerg = (30 * zerg + 239) % P;
            
            break;
        case 2:
            int64_t y;
            std::cin >> x >> y;
            
            x = (x + zerg) % n;
            y = (y + zerg) % n;
            
            unite(x, y);
            
            break;
        case 3:
            std::cin >> x;
            
            x = (x + zerg) % n;
            int64_t q = 0;
            if (x == find(x))
            {
                q = dsu[(int)x].second;
            }
            else
            {
                q = dsu[(int)x].second + dsu[(int)find(x)].second;
            }
            q -= read[(int)x];
            read[(int)x] += q;
            zerg = ((int64_t)100500 * zerg + q) % P;
            std::cout << q << '\n';
            break;
        }
    }
    return 0;
}
