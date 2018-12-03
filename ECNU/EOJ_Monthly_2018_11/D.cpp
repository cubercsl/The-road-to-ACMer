#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(args...)                             \
    do                                           \
    {                                            \
        cout << "\033[32;1m" << #args << " -> "; \
        err(args);                               \
    } while (0)
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/

typedef long long ll;

int main()
{
    ll n, k;
    cin >> n >> k;
    string op;
    if (k == 1)
    {
        ll l = 1, r = (1LL << n) - 1;
        while (l <= r)
        {
            ll m = l + r >> 1;
            cout << m << endl;
            cin >> op;
            if (op == "=") exit(0);
            if (op == ">")
                l = m + 1;
            else
                r = m - 1;
        }
    }
    else if (k <= n)
    {
        for (int i = 0; i < k; i++)
        {
            cout << 1 << endl;
            cin >> op;
            if (op == "=") exit(0);
            if (op == ">") break;
        }
        ll l = 1, r = (1LL << n) - 1;
        for (int i = 1; l <= r; i++)
        {
            ll m = l + r >> 1;
            cout << m << endl;
            cin >> op;
            if (op == "=") exit(0);
            if (i % k == 0)
            {
                if (op == ">")
                    l = m + 1;
                else
                    r = m - 1;
            }
            else
            {
                if (op == "<")
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
    }
    else
    {
        string op1;
        ll l = 1, r = (1LL << n) - 1;
        int x;
        for (int i = 0; l <= r; i++)
        {
            ll m = l + r >> 1;
            cout << m << endl;
            cin >> op;
            if (op == "=") exit(0);
            cout << m << endl;
            cin >> op1;
            if (op1 == op)
            {
                if (op == "<")
                    l = m + 1;
                else
                    r = m - 1;
            }
            else
            {
                string op3;
                cout << m << endl;
                cin >> op3;
                if (op3 == op)
                    x = 2;
                else
                    x = 3;
                if (op3 == "<")
                    l = m + 1;
                else
                    r = m - 1;
                break;
            }
        }
        for (int i = x; l <= r; i++)
        {
            ll m = l + r >> 1;
            cout << m << endl;
            cin >> op;
            if (op == "=") exit(0);
            if (i % k == 0)
            {
                if (op == ">")
                    l = m + 1;
                else
                    r = m - 1;
            }
            else
            {
                if (op == "<")
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
    }
    return 0;
}