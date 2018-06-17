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

int x[8], y[8];
bool check(int a, int b)
{
    return a >= min({x[0], x[1], x[2], x[3]})
           && a <= max({x[0], x[1], x[2], x[3]})
           && b >= min({y[0], y[1], y[2], y[3]})
           && b <= max({y[0], y[1], y[2], y[3]});
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    for (int i = 0; i < 8; i++) scanf("%d%d", x + i, y + i);
    int tx = (x[4] + x[6]) / 2;
    int ty = (y[4] + y[6]) / 2;
    int d = abs(x[4] - tx) + abs(y[4] - ty);
    for (int xx = -100; xx <= 100; xx++)
        for (int yy = -100; yy <= 100; yy++)
            if (abs(xx - tx) + abs(yy - ty) <= d)
                if (check(xx, yy)) return cout << "YES", 0;
    cout << "NO";
    return 0;
}
