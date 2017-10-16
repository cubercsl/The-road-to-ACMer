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

const int maxn = 40;
int n;
int bitmask[maxn];
int dfs(int u, int mask)
{
    int ret = 0;
    mask |= bitmask[u];
    for (int i = u + 1; i < n; i++)
        if ((mask & bitmask[i]) == 0)
            ret = max(ret, dfs(i, mask));
    return ret + 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    char s[25];
    while (~scanf("%d", &n))
    {
        clr(bitmask, 0);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", s);
            for (int j = 0; s[j]; j++)
                bitmask[i] |= 1 << (s[j] - 'a');
        }
        /*for (int i = 0; i < n; i++)
            printf("%d\n", bitmask[i]);*/
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, dfs(i, 0));
        printf("%d\n", ans);
    }
    return 0;
}
