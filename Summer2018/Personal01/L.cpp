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

const int N = 1e6 + 5;
VI d[N];
bool vis[N];

void init()
{
    for (int i = 2; i < N; i++)
        if (!vis[i])
            for (int j = i; j < N; j += i)
                d[j].pb(i), vis[j] = 1;
}

int gao(int n, int x)
{ // n以内与x互质的数的个数
    int ret = 0;
    for (int i = 0; i < (1 << d[x].size()); i++)
    {
        int tmp = 1;
        for (int j = 0; j < d[x].size(); j++)
            if (i >> j & 1) tmp *= d[x][j];
        if (__builtin_parity(i)) tmp *= -1;
        ret += n / tmp;
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    init();
    int t;
    scanf("%d", &t);
    while (t--)
    {
        static int x, p, k;
        scanf("%d%d%d", &x, &p, &k);
        int l = 1, r = 1e8, ans = x;
        int pos = gao(x, p) + k;
        while (l <= r)
        {
            int mid = l + r >> 1;
            int tmp = gao(mid, p);
            if (tmp < pos)
                ans = mid + 1, l = mid + 1;
            else
                r = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
