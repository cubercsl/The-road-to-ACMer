#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, unit, tmp;

struct query
{
    int L, R, id;
} node[maxn];

int ans[maxn];
int num[maxn];
int a[maxn];

bool cmp(query a, query b)
{
    if (a.L / unit != b.L / unit)
        return a.L / unit < b.L / unit;
    else
        return a.R < b.R;
}

void add(int i)
{
    num[i]++;
    if (num[i] % 2)
        tmp++;
    else
        tmp--;
}

void del(int i)
{
    num[i]--;
    if (num[i] % 2)
        tmp++;
    else
        tmp--;
}

void solve()
{
    tmp = 0;
    memset(num, 0, sizeof(num));
    memset(ans, 0, sizeof(ans));
    int L = 1;
    int R = 0;
    for (int i = 0; i < m; i++)
    {
        while (node[i].L < L) add(a[--L]);
        while (node[i].L > L) del(a[L++]);
        while (node[i].R < R) del(a[R--]);
        while (node[i].R > R) add(a[++R]);
        ans[node[i].id] = tmp;
    }

}

int main()
{
    int T;
    int kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < m; i++)
        {
            node[i].id = i;
            scanf("%d%d", &node[i].L, &node[i].R);
        }
        unit = (int)sqrt(n);
        sort(node, node + m, cmp);
        solve();
        printf("Case %d:\n", ++kase);
        for (int i = 0; i < m; i++)
            printf("%s\n", ans[i] > 1 ? "NO" : "YES");
    }
    return 0;
}
