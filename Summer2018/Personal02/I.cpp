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
const int mod = 2520;
const double eps = 1e-6;
unordered_map<int, int> dic;
template <class T>
inline T lcm(T a, T b) { return a * b / __gcd(a, b); };


int a[20];
ll dp[20][2520][50];
ll dfs(int pos, int mod = 0, int lcm = 1, bool limit = true)
{
    if (pos == -1) return mod % lcm == 0;
    int id = dic[lcm];
    if (!limit && dp[pos][mod][id] != -1) return dp[pos][mod][id];
    int up = limit ? a[pos] : 9;
    ll ans = 0;
    for (int i = 0; i <= up; i++)
    {
        if (i)
            ans += dfs(pos - 1, (mod * 10 + i) % 2520, lcm * i / __gcd(lcm, i), limit && i == a[pos]);
        else
            ans += dfs(pos - 1, mod * 10 % 2520, lcm, limit && i == a[pos]);
    }
    if (!limit) dp[pos][mod][id] = ans;
    return ans;
}

ll solve(ll x)
{
    int pos = 0;
    do
        a[pos++] = x % 10;
    while (x /= 10);
    return dfs(pos - 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    vector<int> s;
    for (int i = 0; i < (1 << 9); i++)
    {
        int d = 1;
        for (int j = 0; j < 9; j++)
            if (i >> j & 1) d = lcm(d, j + 1);
        s.push_back(d);
    }
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    for (int i = 0; i < s.size(); i++) dic[s[i]] = i;
    // cout << s.size() << endl;
    // for (auto& t : s) cout << t << endl;
    clr(dp, -1);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        static ll l, r;
        scanf("%lld%lld", &l, &r);
        printf("%lld\n", solve(r) - solve(l - 1));
    }
    return 0;
}
