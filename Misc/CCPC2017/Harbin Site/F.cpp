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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    int a[maxn];
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        int cur = 1;
        for (int i = 0; i < n; i += 2)
            a[i] = cur++;
        for (int i = 1; i < n; i += 2)
            a[i] = cur++;
        for (int i = 0; i < n; i++)
            printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
    }
    return 0;
}
