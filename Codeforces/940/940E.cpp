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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n + 1), dp(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i - 1] + a[i];
    dp[0] = 0;
    deque<ll> q;
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && a[q.back()] > a[i]) q.pop_back();
        q.push_back(i);
        while (q.front() + c <= i) q.pop_front();
        dp[i] = i < c ? dp[i - 1] + a[i] : min(dp[i - 1] + a[i], dp[i - c] + sum[i] - sum[i - c] - a[q.front()]);
    }
    cout << dp[n] << endl;
    return 0;
}