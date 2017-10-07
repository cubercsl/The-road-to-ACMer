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

bool G[100005][4];
bool tmp[20];
bool solve(int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        int q = 0;
        for (int j = 0; j < k; j++)
        {
            if (G[i][j]) flag = false;
            q = q << 1 | G[i][j];
        }
        tmp[q] = true;
        if (flag) return true;
    }
    for (int i = 0; i < 16; i++)
        for (int j = i + 1; j < 16; j++)
            if (tmp[i] && tmp[j] && (i & j) == 0)
                return true;
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, k;
    while (cin >> n >> k)
    {
        clr(G, 0);
        clr(tmp, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < k; j++)
                cin >> G[i][j];
        puts(solve(n, k) ? "YES" : "NO");
    }
    return 0;
}
