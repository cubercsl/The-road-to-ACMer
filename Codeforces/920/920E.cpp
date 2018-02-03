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

const int N = 2e5 + 5;
set<int> all, G[N];
bool vis[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) all.insert(i);
    clr(vis, 0);
    int u, v, s;
    while (m--)
    {
        scanf("%d%d", &u, &v);
        G[u].insert(v);
        G[v].insert(u);
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            int cnt = 0;
            all.erase(i);
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                set<int> tmp;
                u = q.front();
                q.pop();
                vis[u] = 1;
                cnt++;
                for (auto v : all)
                    if (G[u].find(v) == G[u].end()) tmp.insert(v), q.push(v);
                for (auto v : tmp) all.erase(v);
            }
            ans.pb(cnt);
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (auto t : ans) printf("%d ", t);
    return 0;
}
