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

const int maxn = 1005;
int c[maxn];
int d[maxn];

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
        int n, b;
        scanf("%d%d", &n, &b);
        for (int i = 1; i <= n; i++)
            scanf("%d", &c[i]);
        for (int i = 1; i <= n - 1; i++)
            scanf("%d", &d[i]);
        int now = c[1];
        bool flag = 0;
        for (int i = 1; i < n; i++)
        {
            int need = d[i] * b;
            if (need <= now)
                now -= need;
            else
            {
                flag = 1;
                break;
            }
            now += c[i + 1];
        }
        puts(flag ? "No" : "Yes");
    }
    return 0;
}
