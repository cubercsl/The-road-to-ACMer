#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

ll Pow(ll a, ll n, ll mod)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        ll n = 0;
        for (auto& t : s) n = (n * 10 + t - '0') % (mod - 1);
        n = (n - 1 + mod - 1) % (mod - 1);
        cout << Pow(2, n, mod) << endl;
    }
}