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

const int N = 55;
char s[N][N];

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
        for (int i = 0; i < n; i++) scanf("%s", s[i]);
        int ans = 0;
        ans += s[0][0] == '0';
        ans += s[0][n - 1] == '0';
        ans += s[n - 1][0] == '0';
        ans += s[n - 1][n - 1] == '0';
        for (int i = 1; i < n - 1; i++)
        {
            ans += s[0][i] == '0';
            ans += s[i][0] == '0';
            ans += s[n - 1][i] == '0';
            ans += s[i][n - 1] == '0';
        }
        int cnt = 0;
        for (int i = 1; i < n - 1; i++)
            for (int j = 1; j < n - 1; j++)
                cnt += s[i][j] == '1';
        if (ans > cnt)
            puts("-1");
        else
            printf("%d\n", ans);
    }
    return 0;
}