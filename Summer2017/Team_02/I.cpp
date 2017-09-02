#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 9901;
const double eps = 1e-6;

const int maxn = 1e5 + 5;
int bit[maxn];

inline int lowbit(int x)
{
    return x & (-x);
}

void update(int x, int v)
{
    for (int i = x; i < maxn; i += lowbit(i))
        bit[i] += v;
}

int quety(int x)
{
    int sum = 0;
    for (int i = x; i; i -= lowbit(i))
        sum = (sum + bit[i]) % mod;
    return sum;
}

int sum(int l, int r)
{
    return (quety(r) - quety(l - 1) + mod) % mod;
}

int a[maxn];
int b[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int n, d;
    while (cin >> n >> d)
    {
        clr(bit, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        int tot = unique(b, b + n) - b;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int l = lower_bound(b, b + tot, a[i] - d) - b + 1;
            int r = upper_bound(b, b + tot, a[i] + d) - b;
            int tmp = sum(l, r);
            ans = (ans + tmp) % mod;
            int pos = lower_bound(b, b + tot, a[i]) - b + 1;
            update(pos, tmp + 1);
        }
        cout << ans << endl;
    }

    return 0;
}
