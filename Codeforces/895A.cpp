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

const int N = 1000;

int a[N];
int pre_sum[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            a[i + n] = a[i];
        for (int i = 1; i <= 2 * n; i++)
            pre_sum[i] = pre_sum[i - 1] + a[i];
        int ans = 360;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int cur = pre_sum[i + j] - pre_sum[i - 1];
                ans = min(ans, abs(360 - 2 * cur));
            }
        }
        cout << ans << endl;
    }
}