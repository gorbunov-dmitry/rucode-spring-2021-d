#include <bits/stdc++.h>

using namespace std;

bool on_edge(long double x, long double y, long double x1, long double y1, long double x2, long double y2)
{
    double eps = 1e-6;
    bool res = false;
    if (fabs(x2 - x1) < eps)
    {
        if (fabs(x - x1) < eps && y > min(y1, y2) - eps && y - eps < max(y1, y2))
            res = true;
    }
    else
    {
        x -= x1;
        y -= y1;
        x2 -= x1;
        y2 -= y1;
        if (x - eps < max(x1, x2) && x > min(x1, x2) - eps && fabs(x2 * y - y2 * x) < eps)
        {
            res = true;
        }
    }
    return res;
}
bool cross(long double x0, long double y0, long double x1, long double y1, long double x2, long double y2)
{
    double eps = 1e-6;
    return (y1 < y0 && y2 > y0 - eps || y2 < y0 && y1 > y0 - eps) && (y0 * (x1 - x2) + y1 * x2 - x1 * y2) / (y1 - y2) < x0;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);

    long double dl, x0, y0, xs, ys, xt, yt, xi, yi;
    int n;
    cin >> n >> x0 >> y0;
    cin >> xs >> ys;
    xt = xs;
    yt = ys;
    bool par_am = false;
    bool on_side = false;
    n--;
    while (n-- && !on_side)
    {
        cin >> xi >> yi;
        if (on_edge(x0, y0, xt, yt, xi, yi))
        {
            on_side = true;
        }
        if (cross(x0, y0, xt, yt, xi, yi))
        {
            par_am = !par_am;
        }
        xt = xi;
        yt = yi;
    }
    if (on_edge(x0, y0, xt, yt, xs, ys))
    {
        on_side = true;
    }
    if (cross(x0, y0, xt, yt, xs, ys))
    {
        par_am = !par_am;
    }
    cout << (par_am || on_side ? "YES" : "NO");

    return 0;
}