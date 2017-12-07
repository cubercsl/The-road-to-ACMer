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

ll gao(int k)
{
    ll ret = k;
    do
        (ret *= 10) += (k % 10);
    while (k /= 10);
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int k, p;
    while (cin >> k >> p)
    {
        ll ans = 0;
        for (int i = 1; i <= k; i++)
            (ans += gao(i)) %= p;
        cout << ans << endl;
    }
    return 0;
}