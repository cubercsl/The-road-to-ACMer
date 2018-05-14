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

const int N = 1 << 20;
int fa[N];
ll val[N];

int find(int x)
{
    if (fa[x] == x) return x;
    int tmp = find(fa[x]);
    val[x] += val[fa[x]];
    return fa[x] = tmp;
}

void unite(int x, int y, ll s)
{
    int t1 = find(x), t2 = find(y);
    if (t1 == t2) return;
    fa[t2] = t1;
    val[t2] = val[x] - val[y] + s;
}

bool same(int x, int y) { return find(x) == find(y); }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int m;
    while (~scanf("%d", &m))
    {
        vector<int> l(m), r(m), ans(m);
        vector<int> v;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &l[i], &r[i], &ans[i]);
            v.push_back(l[i]), v.push_back(r[i]), v.push_back(l[i] - 1);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 0; i < m; i++)
        {
            l[i] = lower_bound(v.begin(), v.end(), l[i]) - v.begin();
            r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin();
        }
        iota(fa, fa + N, 0);
        memset(val, 0, sizeof(val));
        bool flag = 0;
        for (int i = 0; i < m; i++)
        {
            --l[i];
            if (!same(l[i], r[i]))
                unite(l[i], r[i], ans[i]);
            else if (val[r[i]] - val[l[i]] != ans[i])
            {
                flag = 1;
                break;
            }
        }
        puts(flag ? "666~~~(=_=)" : "2333!(=v=)");
    }
    return 0;
}
