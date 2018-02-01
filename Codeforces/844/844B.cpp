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
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int s[N][N];
    int n, m;
    while (cin >> n >> m)
    {
        ll ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> s[i][j];
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < m; j++)
                cnt += s[i][j];
            ans += (1LL << cnt) - 1;
            ans += (1LL << (m - cnt)) - 1;
        }
        for (int j = 0; j < m; j++)
        {
            int cnt = 0;
            for (int i = 0; i < n; i++)
                cnt += s[i][j];
            ans += (1LL << cnt) - 1;
            ans += (1LL << (n - cnt)) - 1;
        }
        ans -= n * m;
        cout << ans << endl;
    }
    return 0;
}