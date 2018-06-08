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
int a[N];
int d[105][N];
vector<int> G[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m, k, s;
    scanf("%d%d%d%d", &n, &m, &k, &s);
    clr(d, -1);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    while (m--)
    {
        static int u, v;
        scanf("%d%d", &u, &v);
        G[u].pb(v), G[v].pb(u);
    }
    for (int i = 1; i <= k; i++)
    {
        queue<int> q;
        for (int j = 1; j <= n; j++)
            if (a[j] == i) q.push(j), d[i][j] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto& v : G[u])
            {
                if (~d[i][v]) continue;
                d[i][v] = d[i][u] + 1;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        vector<int> v(k);
        for (int j = 1; j <= k; j++) v[j - 1] = d[j][i];
        sort(v.begin(), v.end());
        int sum = 0;
        for (int j = 0; j < s; j++) sum += v[j];
        printf("%d ", sum);
    }
    return 0;
}
