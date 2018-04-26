#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
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

const int N = 105;
int a[N][N];

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
        clr(a, 0);
        while (n--)
        {
            static int x1, x2, y1, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            for (int i = x1; i <= x2; i++)
                for (int j = y1; j <= y2; j++)
                    a[i][j]++;
        }
        int ans = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                ans = max(ans, a[i][j]);
        printf("%d\n", ans);
    }
    return 0;
}