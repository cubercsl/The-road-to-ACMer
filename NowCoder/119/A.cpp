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
int par[maxn], val[maxn];

int find(int x)
{
    if (par[x] == x) return x;
    int tmp = find(par[x]);
    val[x] ^= val[par[x]];
    return par[x] = tmp;
}

void unite(int x, int y, int s)
{
    int t1 = find(x);
    int t2 = find(y);
    if (t1 == t2) return;
    par[t2] = t1;
    val[t2] = (val[x] ^ val[y] ^ s);
}

bool same(int x, int y) { return find(x) == find(y); }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin int n, m;
    cin >> n >> m;
    vector<int> ans;
    clr(val, 0), iota(par, par + maxn, 0);
    for (int i = 0; i < m; i++)
    {
        static int l, r, s;
        cin >> l >> r >> s;
        l--;
        if (!same(l, r))
            unite(l, r, s);
        else if ((val[r] ^ val[l]) != s)
            ans.push_back(i + 1);
    }
    if (ans.empty())
        cout << -1 << endl;
    else
        for (auto& t : ans) cout << t << endl;
    return 0;
}