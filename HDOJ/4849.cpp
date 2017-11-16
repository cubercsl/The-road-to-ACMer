#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1005;
int G[N][N];
ll x[N * N + N], y[N * N + N], z[N * N + N];
int d[N];
bool inq[N];

int main()
{
    int n, m;
    while (~scanf("%d%d%lld%lld%lld%lld", &n, &m, &x[0], &x[1], &y[0], &y[1]))
    {
        for (int i = 2; i < n * n; i++)
        {
            x[i] = (12345 + x[i - 1] * 23456 % 5837501 + x[i - 2] * 34567 % 5837501 + (x[i - 1] * x[i - 2] % 5837501) * 45678 % 5837501) % 5837501;
            y[i] = (56789 + y[i - 1] * 67890 % 9860381 + y[i - 2] * 78901 % 9860381 + (y[i - 1] * y[i - 2] % 9860381) * 89012 % 9860381) % 9860381;
        }
        for (int i = 0; i < n * n; i++)
            z[i] = (x[i] * 90123 % 8475871 + y[i]) % 8475871 + 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i == j)
                    G[i][j] = 0;
                else
                    G[i][j] = z[i * n + j];
        // bfs
        queue<int> q;
        memset(d, 0x3f, sizeof(d));
        memset(inq, 0, sizeof(inq));
        q.push(0);
        d[0] = 0, inq[0] = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (int v = 0; v < n; v++)
            {
                if (d[v] > d[u] + G[u][v])
                {
                    d[v] = d[u] + G[u][v];
                    if (!inq[v])
                    {
                        q.push(v);
                        inq[v] = 1;
                    }
                }
            }
        }
        int ans = INF;
        for (int i = 1; i < n; i++)
            ans = min(ans, d[i] % m);
        printf("%d\n", ans);
    }
    return 0;
}