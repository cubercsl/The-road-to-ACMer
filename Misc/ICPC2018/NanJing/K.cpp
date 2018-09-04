#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;

ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

int main()
{
    string s;
    int x;
    cin >> s >> x;
    vector<int> v(5);
    for (int i = 4; ~i; i--) cin >> v[i];
    --v[0];
    int k;
    cin >> k;
    auto f = [&](int x) {
        long long ans = 0;
        for (int i = 4; ~i; i--) ans = (ans * x + v[i]) % k;
        return ans + 1;
    };
    int r = 0;
    set<int> num;
    int n = 0;
    for (auto& t : s) n = (10LL * n + t - '0') % (mod - 1);
    if (s.length() < 5) k = min(k, n);
    for (int i = 0; i < k; i++)
    {
        num.insert(x);
        x = f(x);
    }
    vector<int> p(14);
    for (auto t : num)
    {
        for (int i = 13; ~i; i--)
        {
            if (t >> i & 1)
            {
                if (!p[i])
                {
                    p[i] = t;
                    break;
                }
                else
                    t ^= p[i];
            }
        }
    }
    for (auto& t : p)
        if (t) r++;
    int t = (n - r + mod - 1) % (mod - 1);
    int ans = (Pow(2, n) - Pow(2, t) + mod) % mod;
    cout << ans << endl;
    return 0;
}