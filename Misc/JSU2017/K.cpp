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
int a[maxn];

int solve(int n, int v)
{
    for (int i = 0; i < n; i++)
    {
        if (v - a[i] <= 0) return i + 1;
        v -= a[i];
    }
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, v;
    while (~scanf("%d%d", &n, &v))
    {
        for (int i = 0; i < n; i++) scanf("%d", a + i);
        sort(a, a + n, greater<int>());
        printf("%d\n", solve(n, v));
    }
    return 0;
}
