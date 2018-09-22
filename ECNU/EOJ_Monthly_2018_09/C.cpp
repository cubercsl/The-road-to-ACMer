#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string _5 = "1 2 2 1 3 ";
string _6 = "3 2 1 1 2 3 ";
string _8 = "1 3 1 3 2 3 2 1";
string _9 = "1 2 3 3 1 2 2 3 1";

const int N = 1 << 18;
int vis[N];

ll go(ll n, ll t, ll sum)
{
    ll tmp = 0;
    for (int i = n; i; i--)
    {
        if (!vis[i] && i + tmp <= sum)
        {
            vis[i] = t;
            tmp += i;
        }
    }
    return tmp;
}

int main()
{
    int n;
    cin >> n;
    long long x = 1LL * n * (n + 1) / 2;
    if (x % 3) return cout << "Impossible" << endl, 0;
    x /= 3;
    ll tmp = 0;
    if (go(n, 1, x) == x && go(n, 2, x) == x && go(n, 3, x) == x)
    {
        for (int i = 1; i <= n; i++) cout << vis[i] << " ";
        return 0;
    }
    return cout << "Impossible" << endl, 0;
}