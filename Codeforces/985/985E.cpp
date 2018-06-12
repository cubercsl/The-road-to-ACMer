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

#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson
const int N = 1 << 20;
bool val[N << 2];
inline void pushup(int rt)
{
    val[rt] = val[lson] | val[rson];
}

void update(int p, int l, int r, int rt)
{
    if (l == r)
    {
        val[rt] = 1;
        return;
    }
    int m = l + r >> 1;
    if (p <= m)
        update(p, Lson);
    else
        update(p, Rson);
    pushup(rt);
}

bool query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R) return val[rt];
    int m = l + r >> 1;
    bool ans = false;
    if (L <= m) ans |= query(L, R, Lson);
    if (m < R) ans |= query(L, R, Rson);
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n);
    for (auto& t : a) cin >> t;
    sort(a.begin(), a.end());
    update(0, 0, n, 1);
    for (int i = 0; i < n; i++)
    {
        int l = lower_bound(a.begin(), a.end(), a[i] - d) - a.begin();
        int r = i - k + 1;
        if (l > r) continue;
        bool ans = query(l, r, 0, n, 1);
        if (ans)
        {
            if (i == n - 1) return cout << "YES", 0;
            update(i + 1, 0, n, 1);
        }
    }
    cout << "NO";
    return 0;
}
