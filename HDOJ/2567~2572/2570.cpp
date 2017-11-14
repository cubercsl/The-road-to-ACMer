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

const int maxn = 105;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    int a[maxn];
    cin >> T;
    while (T--)
    {
        int n, v, w;
        cin >> n >> v >> w;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        double sum = 0;
        int i;
        for (i = 0; i < n; i++)
        {
            if (sum + a[i] <= w * (i + 1))
                sum += a[i];
            else break;
        }
        if (!sum)
            printf("0 0.00\n");
        else
            printf("%d %.2f\n", v * i, sum / (i * 100));
    }
    return 0;
}