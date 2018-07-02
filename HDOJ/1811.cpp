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
    vector<int> fa;
    function<int(int)> find = [&](int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); };
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        vector<PII> a;
        vector<vector<int> > G(n);
        vector<int> deg(n);
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        int t = n;
        while (m--)
        {
            static int u, v;
            static char c;
            scanf("%d %c %d", &u, &c, &v);
            if (c == '=')
            {
                u = find(u), v = find(v);
                if (u == v) continue;
                fa[u] = v, --t;
            }
            else
            {
                if (c == '<') swap(u, v);
                a.push_back({u, v});
            }
        }
        for (auto& item : a)
        {
            int u = find(item.first), v = find(item.second);
            G[u].push_back(v);
            ++deg[v];
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (!deg[i] && find(i) == i) q.push(i);
        bool flag = false;
        while (!q.empty())
        {
            if (q.size() > 1) flag = true;
            int u = q.front();
            q.pop();
            --t;
            for (auto& v : G[u])
                if (--deg[v] == 0) q.push(v);
        }
        if (t)
            puts("CONFLICT");
        else if (flag)
            puts("UNCERTAIN");
        else
            puts("OK");
    }
    return 0;
}
