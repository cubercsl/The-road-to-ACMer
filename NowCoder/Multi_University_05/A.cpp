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
int bit[maxn];
int a[maxn];
inline void add(int x)
{
    for (int i = x; i < maxn; i += i & -i) bit[i]++;
}

inline int query(int x)
{
    int t = 0;
    for (int i = x; i; i -= i & -i) t += bit[i];
    return t;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        a[i] = num + 1;
    }
    ll ans = 0;
    for (int i = n - 1; ~i; i--)
    {
        add(a[i]);
        ans += query(a[i] - 1);
    }
    cout << ans << endl;
    return 0;
}
