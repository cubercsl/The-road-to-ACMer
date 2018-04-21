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
struct L_B
{
    int d[31];
    L_B() { memset(d, 0, sizeof(d)); }
    bool insert(int val)
    {
        for (int i = 30; ~i; i--)
            if (val >> i & 1)
            {
                if (!d[i])
                {
                    d[i] = val;
                    break;
                }
                val ^= d[i];
            }
        return val > 0;
    }
    int query_max()
    {
        int ret = 0;
        for (int i = 30; ~i; i--)
            if ((ret ^ d[i]) > ret) ret ^= d[i];
        return ret;
    }
} base[N];

L_B merge(const L_B& a, const L_B& b)
{
    L_B ret = a;
    for (int i = 30; ~i; i--)
        if (b.d[i]) ret.insert(b.d[i]);
    return ret;
}

int fa[N], ans;
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y) return;
    fa[y] = x;
    base[x] = merge(base[x], base[y]);
    ans = max(ans, base[x].query_max());
}

bool ok[N];
int a[N], b[N],ret[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) scanf("%d", b + i);
    for (int i = n; i; i--)
    {
        ok[b[i]] = 1;
        base[b[i]].insert(a[b[i]]);
        ans = max(ans, base[b[i]].query_max());
        if (ok[b[i] - 1]) unite(b[i], b[i] - 1);
        if (ok[b[i] + 1]) unite(b[i], b[i] + 1);
        ret[i] = ans;
    }
    for (int i = 1; i <= n; i++) printf("%lld\n", ret[i]);
    return 0;
}