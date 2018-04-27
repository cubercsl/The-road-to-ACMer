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

const int N = 1 << 10;
int fa[N];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y) fa[x] = y;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    iota(fa, fa + n, 0);
    int ans = 0;
    vector<PII> v;
    for (int i = 0, x, y; i < n; i++)
    {
        cin >> x >> y;
        for (int j = 0; j < i; j++)
        {
            int xx = v[j].X, yy = v[j].Y;
            if (xx == x || yy == y) unite(i, j);
        }
        v.push_back({x, y});
    }
    for (int i = 0; i < n; i++)
        if (find(i) == i) ans++;
    cout << ans - 1 << endl;
    return 0;
}
