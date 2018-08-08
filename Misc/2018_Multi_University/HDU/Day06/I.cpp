#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
vector<int> G[N];
int v[N];
char buf[20];
int fa[N], vill[N], sure[N];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y) fa[x] = y;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) G[i].clear(), sure[i] = 0;
        iota(fa, fa + n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%s", &v[i], buf);
            vill[i] = (buf[0] == 'v');

            if (vill[i])
            {
                G[v[i]].push_back(i);
                unite(i, v[i]);
            }
        }
        static int q[N];
        int head = 0, tail = 0;
        for (int i = 1; i <= n; i++)
            if (!vill[i])
            {
                int fx = find(i);
                int fy = find(v[i]);
                if (fx != fy) continue;
                q[tail++] = v[i];
                sure[v[i]] = 1;
            }
        for (int u; head != tail; head++)
        {
            u = q[head];
            for (auto& v : G[u])
            {
                if (!sure[v])
                {
                    q[tail++] = v;
                    sure[v] = 1;
                }
            }
        }
        printf("0 %d\n", head);
    }
}