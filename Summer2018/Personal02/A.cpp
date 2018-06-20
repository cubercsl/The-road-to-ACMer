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

const int N = 1 << 8;
int dp[N];

int dfs(int u)
{
    if (u == 0) return dp[u] = 0;
    if (~dp[u]) return dp[u];
    set<int> s;
    for (int i = 0; i < u; i++) s.insert(dfs(i));
    for (int i = 1; i <= u / 2; i++)
    {
        int tmp = dfs(i) ^ dfs(u - i);
        s.insert(tmp);
    }
    for (int i = 0;; i++)
        if (s.find(i) == s.end()) return dp[u] = i;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    /*
    clr(dp, -1);
    for (int i = 0; i < 100; i++)
        printf("sg[%d] = %d\n", i, dfs(i));
    */
    auto f = [](ll x) {
        if (x % 4 == 3) return x + 1;
        if (x % 4 == 0) return x - 1;
        return x;
    };
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        ll sg = 0;
        for (int i = 0, x; i < n; i++)
            scanf("%d", &x), sg ^= f(x);
        puts(sg ? "Alice" : "Bob");
    }
    return 0;
}
