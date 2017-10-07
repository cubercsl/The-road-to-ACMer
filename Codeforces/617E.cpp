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

const int maxn = 1 << 20;
int pos[maxn];
int a[maxn];
ll cnt[maxn];
ll ans[maxn];
struct node
{
    int l, r, id;
} query[maxn];
void add(int x, int k, ll& ans)
{
    ans += cnt[x ^ k];
    cnt[x]++;
}
void del(int x, int k, ll& ans)
{
    cnt[x]--;
    ans -= cnt[x ^ k];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m, k;
    while (~scanf("%d%d%d", &n, &m, &k))
    {
        clr(cnt, 0);
        double unit = sqrt(n);
        for (int i = 1; i <= n; i++) scanf("%d", a + i), a[i] ^= a[i - 1], pos[i] = i / unit;
        for (int i = 0; i < m; i++) scanf("%d%d", &query[i].l, &query[i].r), query[i].id = i;
        // for (int i = 1; i <= n; i++) printf("pos:%d\n", pos[i]);
        sort(query, query + m, [](node a, node b) { return pos[a.l] < pos[b.l] || (pos[a.l] == pos[b.l] && a.r < b.r); });
        int L = 1, R = 0;
        ll tmp = 0;
        cnt[0] = 1;
        for (int i = 0; i < m; i++)
        {
            int l = query[i].l, r = query[i].r;
            while (l < L) add(a[--L - 1], k, tmp);
            while (l > L) del(a[L++ - 1], k, tmp);
            while (r < R) del(a[R--], k, tmp);
            while (r > R) add(a[++R], k, tmp);
            ans[query[i].id] = tmp;
        }
        for (int i = 0; i < m; i++)
            printf("%lld\n", ans[i]);
    }
    return 0;
}
