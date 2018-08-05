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

const int maxn = 1e5 + 5;
int n, m;
PII a[maxn];

void merge()
{
    int tot = 0;
    int L = a[0].X;
    int R = a[0].Y;
    for (int i = 1; i < n; i++)
    {
        if (R + 1 < a[i].X)
            a[tot++] = mp(L, R), L = a[i].X, R = a[i].Y;
        else if (R < a[i].Y)
            R = a[i].Y;
    }
    a[tot++] = mp(L, R);
    n = tot;
}

void solve()
{
    int l = 0, r = 0, len = 0, ans = 0;
    while (l < n)
    {
        while (r + 1 < n && len + a[r + 1].X - a[r].Y - 1 <= m)
            len += a[r + 1].X - a[r].Y - 1, r++;
        ans = max(ans, a[r].Y - a[l].X + m - len + 1);
        len -= a[l + 1].X - a[l].Y - 1;
        l++;
    }
    printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 0; i < n; i++)
            scanf("%d%d", &a[i].X, &a[i].Y);
        sort(a, a + n);
        merge();
        solve();
    }
    return 0;
}
