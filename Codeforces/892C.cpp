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

const int N = 2005;
int num[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n))
    {
        int ans = INF;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &num[i]);
            if (num[i] == 1) cnt++;
        }
        if (cnt)
        {
            printf("%d\n", n - cnt);
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            int tmp = 0;
            for (int j = i; j <= n; j++)
            {
                tmp = __gcd(tmp, num[j]);
                if (tmp == 1) ans = min(ans, j - i + n - 1);
            }
        }
        if (ans == INF)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}