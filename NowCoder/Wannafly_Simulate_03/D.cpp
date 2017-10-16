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

const int maxn = 505;
int deg[maxn];

int solve(int n)
{
    int _3 = 0, _4 = 0;
    for (int i = 0; i < n; i++)
    {
        if (deg[i] == 3)
            _3++;
        else if (deg[i] == 4)
            _4++;
        else if (deg[i] < 1 || deg[i] > 4)
            return 0;
        if (_3 + _4 > 1) return 0;
    }
    if (_4 == 1) return 1;
    if (_3 == 1) return 2;
    return 3;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin int n, m;
    while (cin >> n >> m)
    {
        clr(deg, 0);
        while (m--)
        {
            static int u, v;
            cin >> u >> v;
            u--, v--;
            deg[u]++, deg[v]++;
        }
        int ans = solve(n);
        switch (ans)
        {
        case 0: cout << "NotValid" << endl; break;
        case 1: cout << "X" << endl; break;
        case 2: cout << "Y" << endl; break;
        case 3: cout << "I" << endl; break;
        }
    }
    return 0;
}
