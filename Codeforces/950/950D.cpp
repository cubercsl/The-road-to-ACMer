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

ll dfs(ll x, ll n)
{
    if (x & 1) return x / 2 + 1;
    if (n & 1)
        return dfs(x == 2 ? (n - 1) : (x - 2), n - 1) + 1;
    return dfs(x / 2, n / 2) + n / 2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int q;
    ll n;
    cin >> n >> q;
    while (q--)
    {
        ll x;
        cin >> x;
        cout << dfs(x, n) << endl;
    }
    return 0;
}