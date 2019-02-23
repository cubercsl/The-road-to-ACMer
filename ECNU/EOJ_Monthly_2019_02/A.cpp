#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 4e9;

void ask(ll x, ll y, ll z)
{
    cout << 0 << ' ' << x << ' ' << y << ' ' << z << endl;
}

ll solvex0()
{
    ll l = -INF, r = 0;
    ll op, ans;
    while (l <= r)
    {
        ll x = l + r >> 1;
        ask(x, 0, 0);
        cin >> op;
        if (op == 0)
            l = x + 1;
        else
            r = x - 1, ans = x;
    }
    return ans;
}

ll solvex1()
{
    ll l = 0, r = INF;
    ll op, ans;
    while (l <= r)
    {
        ll x = l + r >> 1;
        ask(x, 0, 0);
        cin >> op;
        if (op == 0)
            r = x - 1;
        else
            l = x + 1, ans = x;
    }
    return ans;
}

ll solvey0()
{
    ll l = -INF, r = 0;
    ll op, ans;
    while (l <= r)
    {
        ll x = l + r >> 1;
        ask(0, x, 0);
        cin >> op;
        if (op == 0)
            l = x + 1;
        else
            r = x - 1, ans = x;
    }
    return ans;
}

ll solvey1()
{
    ll l = 0, r = INF;
    ll op, ans;
    while (l <= r)
    {
        ll x = l + r >> 1;
        ask(0, x, 0);
        cin >> op;
        if (op == 0)
            r = x - 1;
        else
            l = x + 1, ans = x;
    }
    return ans;
}
ll solvez0()
{
    ll l = -INF, r = 0;
    ll op, ans;
    while (l <= r)
    {
        ll x = l + r >> 1;
        ask(0, 0, x);
        cin >> op;
        if (op == 0)
            l = x + 1;
        else
            r = x - 1, ans = x;
    }
    return ans;
}

ll solvez1()
{
    ll l = 0, r = INF;
    ll op, ans;
    while (l <= r)
    {
        ll x = l + r >> 1;
        ask(0, 0, x);
        cin >> op;
        if (op == 0)
            r = x - 1;
        else
            l = x + 1, ans = x;
    }
    return ans;
}
int main()
{
    ll x0 = solvex0();
    ll x1 = solvex1();
    ll y0 = solvey0();
    ll y1 = solvey1();
    ll z0 = solvez0();
    ll z1 = solvez1();
    cout << 1 << ' ' << (x0 + x1) / 2 << ' ' << (y0 + y1) / 2 << ' ' << (z0 + z1) / 2 << endl;
}