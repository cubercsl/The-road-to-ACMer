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
    int n, k;
    while (cin >> n >> k)
    {
        vector<ll> v(n), dp(n + 1);
        for (auto& t : v) cin >> t;
        v.push_back(0);
        ++k;
        deque<int> q;
        for (int i = 0; i < k; i++)
        {
            dp[i] = v[i];
            while (!q.empty() && dp[q.back()] > dp[i]) q.pop_back();
            q.push_back(i);
        }
        for (int i = k; i <= n; i++)
        {
            while (q.front() + k < i) q.pop_front();
            dp[i] = dp[q.front()] + v[i];
            while (!q.empty() && dp[q.back()] > dp[i]) q.pop_back();
            q.push_back(i);
        }
        cout << accumulate(v.begin(), v.end(), 0LL) - dp[n] << endl;
    }
    return 0;
}