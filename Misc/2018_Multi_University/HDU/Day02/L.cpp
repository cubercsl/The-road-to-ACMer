// ybmj
#include <bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define lson_len (len - (len >> 1))
#define rson_len (len >> 1)
#define pb(x) push_back(x)
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const int maxn = 1 << 20;
vector<int> a, b;
int BIT[maxn];

inline int getid(int x)
{
    return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
}
inline int lowb(int x) { return x & (-x); }
void add(int x)
{
    while (x < b.size())
    {
        BIT[x]++;
        x += lowb(x);
    }
}
int sum(int x)
{
    int ret = 0;
    while (x > 0)
    {
        ret += BIT[x];
        x -= lowb(x);
    }
    return ret;
}
int main()
{
// /*
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    // */
    std::ios::sync_with_stdio(false);
    int n, x, y;
    while (cin >> n >> x >> y)
    {
        a.resize(n + 5);
        b.resize(n + 5);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        b.resize(distance(b.begin(), unique(b.begin(), b.end())));
        sort(b.begin(), b.end());
        ll ans = 0;
        clr(BIT, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            ans += sum(getid(a[i]) - 1);
            add(getid(a[i]));
        }
        cout << ans * min(x, y) << endl;
    }
}