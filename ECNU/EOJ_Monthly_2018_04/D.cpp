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
ll bit[N];

void update(int x, int v)
{
    for (int i = x; i < N; i += i & -i) bit[i] += v;
}

ll query(int x)
{
    ll t = 0;
    for (int i = x; i; i -= i & -i) (t += bit[i]) %= mod;
    return t;
}

PII a[N];
int b[N];
struct Node
{
    int x, y;
    int id;
    bool operator<(const Node& rhs)
    {
        return mp(x, y) < mp(rhs.x, rhs.y);
    }
} aa[N];
ll ans[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].X >> a[i].Y, b[i] = a[i].Y;
    sort(b, b + n);
    int m = unique(b, b + n) - b;
    for (int i = 0; i < n; i++) aa[i].x = a[i].X, aa[i].y = lower_bound(b, b + m, a[i].Y) - b + 1, aa[i].id = i;
    sort(aa, aa + n);
    for (int i = 0; i < n; i++)
    {
        ans[aa[i].id] = 1 + query(aa[i].y);
        update(aa[i].y, ans[aa[i].id]);
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    return 0;
}