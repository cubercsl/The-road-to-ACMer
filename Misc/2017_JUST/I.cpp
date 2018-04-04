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

const int N = 1 << 18;
vector<int> G[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        for (int i = 0; i < N; i++) vector<int>().swap(G[i]);
        int n;
        scanf("%d", &n);
        vector<int> c(n);
        vector<int> d(n, INF);
        for (auto& t : c) scanf("%d", &t);
        for (int i = 0; i < n; i++) G[c[i]].push_back(i);
        queue<int> q;
        q.push(0);
        vector<int> inq(n);
        d[0] = 0;
        inq[0] = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            int col = c[u];
            int v = u + 1;
            if(v == n) continue;
            if (d[u] + 1 < d[v])
            {
                d[v] = d[u] + 1;
                if (!inq[v])
                {
                    q.push(v);
                    inq[v] = 1;
                }
            }
            auto pos = upper_bound(G[col].begin(), G[col].end(), u);
            if (pos == G[col].end()) continue;
            v = *pos;
            if (d[u] + 1 < d[v])
            {
                d[v] = d[u] + 1;
                if (!inq[v])
                {
                    q.push(v);
                    inq[v] = 1;
                }
            }
        }
        printf("%d\n", d[n - 1]);
    }
    return 0;
}