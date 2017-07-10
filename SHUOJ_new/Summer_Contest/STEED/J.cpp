#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

ll euler (ll n)
{
    ll rt = n;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            rt -= rt / i;
            while (n % i == 0) n /= i;
        }
    if (n > 1)rt -= rt / n;
    return rt;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = (1 + n) * n / 2;
        ans %= mod;
        for (int i = 1; i < 233; i++)
            ans = (ans - (euler(i) * (n / i) % mod) + mod) % mod;
        for (int i = n - 232; i <= n; i++)
            ans = (ans - (euler(i) * (n / i) % mod) + mod) % mod;
        cout << ans << endl;
    }
    return 0;
}
