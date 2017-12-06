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

const int N = 1 << 17;
int a[N];

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    int n, d;
    while (~scanf("%d%d", &n, &d))
    {
        int cnt = 0, tmp = 0;
        a[0] = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int bal = 0;
        for (int i = 0; i <= n; i++)
        {
            if (a[i] == 0)
            {

                int cur = 0, mm = -INF;
                for (int j = i + 1; a[j] && j <= n; j++)
                    cur += a[j], mm = max(cur, mm);
                if (d - mm < 0)
                {
                    cnt = -1;
                    break;
                }
                if (bal >= 0) continue;
                cnt++;
                bal = d - mm;
            }
            bal += a[i];
        }
        printf("%d\n", cnt);
    }
    return 0;
}