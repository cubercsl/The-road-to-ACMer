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
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    int a[105][105];
    int pre[105];
    int n, m, k;
    while (cin >> n >> m >> k)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        int cnt = 0, score = 0;
        for (int j = 1; j <= m; j++)
        {
            for (int i = 1; i <= n; i++)
                pre[i] = pre[i - 1] + a[i][j];
            int mm = 0, ch = 0;
            for (int i = 1; i <= n; i++)
                if (a[i][j] == 1)
                {
                    int tmp = pre[i - 1 + min(k, n - i + 1)] - pre[i - 1];
                    if (tmp > mm) mm = tmp, ch = pre[i - 1];
                }
            cnt += ch, score += mm;
        }
        cout << score << " " << cnt << endl;
    }
    return 0;
}
