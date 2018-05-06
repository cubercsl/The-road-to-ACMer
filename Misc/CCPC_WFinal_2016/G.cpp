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
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int T;
    cin >> T;
    while (T--)
    {
        int q, k;
        cin >> q >> k;
        while (q--)
        {
            int n, m;
            cin >> n >> m;
            if (n > m) swap(n, m);
            int x = n / (k + 1), y = n % (k + 1);
            if (y == 0)
            {
                puts("Alice");
                continue;
            }
            if (k == 1)
                puts((n + m) & 1 ? "Alice" : "Bob");
            else
                puts(((n + m) & 1) ^ (x & 1) ? "Alice" : "Bob");
        }
    }
    return 0;
}