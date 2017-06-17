#include <bits/stdc++.h>
#define ql node[i].L
#define qr node[i].R
using namespace std;

const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;
int n, m, unit;
int a[maxn];
int num[maxm];
long long ans[maxn];
long long tmp;

struct query
{
    int L, R, id;
} node[maxn];

bool cmp(query a, query b)
{
    if (a.L / unit == b.L / unit)
        return a.R < b.R;
    return a.L / unit < b.L / unit;
}

void add(int i)
{
    tmp += (2ll * num[i] + 1ll) * i;
    num[i]++;
}

void del(int i)
{
    tmp -= (2ll * num[i] - 1ll) * i;
    num[i]--;
}

void solve()
{
    tmp = 0;
    int L = 1, R = 0;
    for (int i = 0; i < m; i++)
    {
        while (ql < L) add(a[--L]);
        while (ql > L) del(a[L++]);
        while (qr < R) del(a[R--]);
        while (qr > R) add(a[++R]);
        ans[node[i].id] = tmp;
    }

}

int main()
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
    for (int i = 0; i < m; i++)
        printf("%lld\n", ans[i]);
    return 0;
}
