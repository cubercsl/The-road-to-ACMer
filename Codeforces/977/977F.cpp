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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& t : v) cin >> t;
    map<int, int> mem;
    vector<int> dp(n + 1);
    int ans = 0, pos = -1;
    for (int i = 0; i < n; i++)
    {
        int tmp = mem[v[i] - 1];
        dp[i + 1] = tmp + 1;
        mem[v[i]] = max(mem[v[i]], dp[i + 1]);
        if (dp[i + 1] > ans) ans = dp[i + 1], pos = i;
    }
    cout << ans << endl;
    int now = v[pos];
    stack<int> s;
    for (int i = pos; ~i; i--)
    {
        if (v[i] == now)
        {
            s.push(i + 1);
            now--;
        }
    }
    while (!s.empty()) cout << s.top() << " ", s.pop();

    return 0;
}