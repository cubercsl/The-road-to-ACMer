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

bool vis[15];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int h, m, s, t1, t2;
    while (cin >> h >> m >> s >> t1 >> t2)
    {
        double H, M, S = s;
        M = m + S / 60;
        H = h * 5.0 + M / 60;
        // cout << H << " " << M << " " << S << endl;
        t1 *= 5;
        t2 *= 5;
        if (t1 > t2) swap(t1, t2);
        if ((H < t1 || H > t2) && (M < t1 || M > t2) && (S < t1 || S > t2))
        {
            puts("YES");
            continue;
        }
        if ((H > t1 && H < t2) && (M > t1 && M < t2) && (S > t1 && S < t2))
        {
            puts("YES");
            continue;
        }
        puts("NO");
    }
    return 0;
}
