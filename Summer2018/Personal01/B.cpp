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
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> a(n);
        for (auto& t : a) scanf("%d", &t);
        int p = -1;
        for (int i = 0; i < n; i++)
            if (~a[i])
            {
                p = i;
                break;
            }
        for (int i = p + 1; i < n; i++) a[i] = (a[i - 1] + 1) % m;
        for (int i = p - 1; ~i; i--) a[i] = (a[i + 1] - 1 + m) % m;
        for (int i = 0; i < n; i++) printf("%d%c", a[i], " \n"[i == n - 1]);
    }
    return 0;
}
