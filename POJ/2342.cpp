#include <iostream>
#include <vector>
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

const int maxn = 6005;

int n;
int dp[maxn][2];
bool vis[maxn];
int par[maxn];


void dfs(int rt)
{
    vis[rt] = true;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && par[i] == rt)
        {
            dfs(i);
            dp[rt][1] += dp[i][0];
            dp[rt][0] += max(dp[i][0], dp[i][1]);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> dp[i][1];
    int rt = 0;
    int l, k;
    while (cin >> l >> k, l + k)
    {
        par[l] = k;
        rt = k;
    }
    dfs(rt);
    cout << max(dp[rt][0], dp[rt][1]) << endl;
    return 0;
}
