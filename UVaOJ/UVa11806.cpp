// Cheerleaders, UVa11806

/*Sample Input
2
2 2 1
2 3 2
*/

#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e6 + 7;
const double eps = 1e-6;

const int maxn = 1010;
int C[maxn][maxn];
int n, m, k;

void init()
{
    C[0][0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t, kase = 0;
    init();
    cin >> t;
    while (t--)
    {
        cin >> m >> n >> k;
        int ans = 0;
        for (int i = 0; i < 16; i++)
        {
            bool flag = 0;
            int r = m, c = n;
            if (i & 1) c--, flag ^= 1;
            if (i & 2) c--, flag ^= 1;
            if (i & 4) r--, flag ^= 1;
            if (i & 8) r--, flag ^= 1;
            if (flag) ans = (ans - C[r * c][k] + mod) % mod;
            else ans = (ans + C[r * c][k]) % mod;
        }
        cout << "Case " << ++kase << ": " << ans << endl;
    }

    return 0;
}
