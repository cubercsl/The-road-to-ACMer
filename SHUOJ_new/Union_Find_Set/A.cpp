#include <bits/stdc++.h>
#define input(n) while(cin >> n)
#define input_2(a, b) while(cin >> a >> b)
#define Tcase int T; cin >> T; while(T--)
#define clr(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x & -x)
#define Lson L, mid, node << 1
#define Rson mid + 1, R, node << 1 | 1
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 1e5 + 5;
vector <int> G[maxn];
int n, ans;

void dfs(int tmp, int u, int dis)
{
    ans = max(dis, ans);
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (tmp != v)
            dfs(u, v, dis + 1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    input(n)
    {
        for (int i = 0; i < maxn; i++)
            G[i].clear();
        ans = -INF;
        for (int i = 1; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            G[a].pb(b);
            G[b].pb(a);
        }
        dfs(0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}
