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

const int maxn = 1 << 17;
int tree[20][maxn];
int sorted[maxn];
int toleft[20][maxn];

#define Lson l, m, dep + 1
#define Rson m + 1, r, dep + 1

void build(int l, int r, int dep)
{
    if (l == r) return;
    int m = (l + r) >> 1, same = m - l + 1;
    for (int i = l; i <= r; i++)
        if (tree[dep][i] < sorted[m])
            same--;
    int lpos = l;
    int rpos = m + 1;
    for (int i = l; i <= r; i++)
    {
        if (tree[dep][i] < sorted[m])
            tree[dep + 1][lpos++] = tree[dep][i];
        else if (tree[dep][i] == sorted[m] && same > 0)
        {
            tree[dep + 1][lpos++] = tree[dep][i];
            same--;
        }
        else
            tree[dep + 1][rpos++] = tree[dep][i];
        toleft[dep][i] = toleft[dep][l - 1] + lpos - l;
    }
    build(Lson);
    build(Rson);
}

int query(int L, int R, int k, int l, int r, int dep)
{
    if (L == R) return tree[dep][L];
    int m = (l + r) >> 1;
    int cnt = toleft[dep][R] - toleft[dep][L - 1];
    if (cnt >= k)
    {
        int newl = l + toleft[dep][L - 1] - toleft[dep][l - 1];
        int newr = newl + cnt - 1;
        return query(newl, newr, k, Lson);
    }
    else
    {
        int newr = R + toleft[dep][r] - toleft[dep][R];
        int newl = newr - (R - L - cnt);
        return query(newl, newr, k - cnt, Rson);
    }
}

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
        int n, m;
        scanf("%d%d", &n, &m);
        clr(tree, 0);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &tree[0][i]);
            sorted[i] = tree[0][i];
        }
        sort(sorted + 1, sorted + n + 1);
        build(1, n, 0);
        while (m--)
        {
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            int L = 1, R = r - l + 1;
            int ans = 0;
            while (L <= R)
            {
                int m = (L + R) >> 1;
                if (query(l, r, m, 1, n, 0) < k)
                    L = m + 1, ans = m;
                else
                    R = m - 1;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
