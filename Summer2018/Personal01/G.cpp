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
int minv[N], maxv[N];
int a[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        maxv[0] = 0, minv[n + 1] = INF;
        for (int i = 1; i <= n; i++) maxv[i] = max(maxv[i - 1], a[i]);
        for (int i = n; i; i--) minv[i] = min(minv[i + 1], a[i]);
        int ans = 0;
        for (int i = 2; i < n; i++) ans += (a[i] <= minv[i + 1] && a[i] >= maxv[i - 1]);
        printf("%d\n", ans);
    }
    return 0;
}