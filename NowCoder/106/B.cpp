#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

inline ll inv(ll x) { return Pow(x, mod - 2); }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.length();
    ll t = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '5' || s[i] == '0') (t += Pow(2, i)) %= mod;
    ll q = Pow(2, n);
    ll ans = t * ((1 - Pow(q, k)) + mod) % mod * inv((1 - q + mod) % mod) % mod;
    cout << ans << endl;
    return 0;
}
