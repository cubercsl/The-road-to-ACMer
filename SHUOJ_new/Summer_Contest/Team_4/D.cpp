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
const double eps = 1e-6;

const int MAXN = 3005;
vector<int> G[MAXN];
int uN;
int Mx[MAXN], My[MAXN];
int dx[MAXN], dy[MAXN];
int dis;
bool used[MAXN];
bool SearchP()
{
    queue<int> Q;
    dis = INF;
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    for (int i = 0; i < uN; i++)
        if (Mx[i] == -1)
        {
            Q.push(i);
            dx[i] = 0;
        }
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if (dx[u] > dis) break;
        int sz = G[u].size();
        for (int i = 0; i < sz; i++)
        {
            int v = G[u][i];
            if (dy[v] == -1)
            {
                dy[v] = dx[u] + 1;
                if (My[v] == -1)
                    dis = dy[v];
                else
                {
                    dx[My[v]] = dy[v] + 1;
                    Q.push(My[v]);
                }
            }
        }
    }
    return dis != INF;
}

bool DFS(int u)
{
    int sz = G[u].size();
    for (int i = 0; i < sz; i++)
    {
        int v = G[u][i];
        if (!used[v] && dy[v] == dx[u] + 1)
        {
            used[v] = true;
            if (My[v] != -1 && dy[v] == dis) continue;
            if (My[v] == -1 || DFS(My[v]))
            {
                My[v] = u;
                Mx[u] = v;
                return true;
            }
        }
    }
    return false;
}
int MaxMatch()
{
    int res = 0;
    memset(Mx, -1, sizeof(Mx));
    memset(My, -1, sizeof(My));
    while (SearchP())
    {
        memset(used, false, sizeof(used));
        for (int i = 0; i < uN; i++)
            if (Mx[i] == -1 && DFS(i))
                res++;
    }
    return res;
}

PII guest[MAXN];
int speed[MAXN];
PII unbrella[MAXN];

int dist2(PII a, PII b)
{
    int dx = a.X - b.X;
    int dy = a.Y - b.Y;
    return dx * dx + dy * dy;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, t;
        scanf("%d", &t);
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
            scanf("%d%d%d", &guest[i].X, &guest[i].Y, &speed[i]);
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &unbrella[i].X, &unbrella[i].Y);
        uN = m;
        for (int i = 0; i < m; i++)
            G[i].clear();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dist2(unbrella[i], guest[j]) <= speed[i] * speed[i] * t * t)
                    G[i].pb(j);
        printf("Scenario #%d:\n%d\n\n", ++kase, MaxMatch());
    }
    return 0;
}
