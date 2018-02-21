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

const char d[] = "UR";
inline int dir(const char c)
{
    for (int i = 0; i < 2; i++)
        if (c == d[i]) return i;
    assert(false);
}
int dx[] = {0, 1};
int dy[] = {1, 0};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (cin >> n)
    {
        char c;
        int x = 0, y = 0, ans = 0, last = -1;
        while (n--)
        {
            cin >> c;
            if(x == y && dir(c) == last) ans++;
            x += dx[dir(c)], y += dy[dir(c)];
            last = dir(c);
        }
        cout << ans << endl;
    }
    return 0;
}