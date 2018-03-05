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

const int N = 1 << 17;
vector<int> G[N];
int dp[N];
void dfs(int u, int dep)
{
    ++dp[dep];
    for (auto& v : G[u]) dfs(v, dep + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        static int fa;
        cin >> fa;
        G[fa].pb(i);
    }
    dfs(1, 1);
    int res = 0;
    for (int i = 1; i <= n; i++) res += (dp[i] & 1);
    cout << res << endl;
    return 0;
}