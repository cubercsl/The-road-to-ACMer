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

const int maxn =  20010;
bool vis[maxn], used[maxn];
vector <int> G[maxn];
int sum, a;

void init()
{
    clr(vis, 0);
    clr(used, 0);
    for (int i = 0; i < maxn; i++)
        G[i].clear();
}

void add_edge(int u, int v)
{
    G[u].pb(v);
    G[v].pb(u);
}

void dfs(int u, bool flag)
{
    sum++;
    if (flag) a++;
    vis[u] = true;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (vis[v]) continue;
        dfs(v, !flag);
    }

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int t, kase = 0;
    cin >> t;
    while (t--)
    {
        int m = 0;
        init();
        int n;
        cin >> n;
        while (n--)
        {
            int u, v;
            cin >> u >> v;
            m = max(m, max(u, v));
            u--, v--;
            add_edge(u, v);
            used[u] = used[v] = true;
        }
        int ans = 0;
        for (int i = 0;i<m;i++)
        {
            if(!used[i])
                continue;
            if(vis[i])
                continue;
            sum=a=0;
            dfs(i,0);
            ans+=max(a,sum-a);
        }
        cout<<"Case "<<++kase<<": "<<ans<<endl;
    }
    return 0;
}

