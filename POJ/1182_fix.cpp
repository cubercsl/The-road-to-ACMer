#include <cstdio>
#include <string>
#include <vector>
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

const int maxn = 50010;
int par[maxn], val[maxn];
int n, k;

void init(int n)
{
    for (int i = 0; i <= n; i++) par[i] = i, val[i] = 0;
}

int find(int x)
{
    if (par[x] == x) return x;
    int tmp = find(par[x]);
    (val[x] += val[par[x]]) %= 3;
    return par[x] = tmp;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    init(n);
    int cnt = 0;
    while (k--)
    {
        int d, x, y;
        scanf("%d%d%d", &d, &x, &y);
        if (x > n || y > n)
        {
            cnt++;
            continue;
        }
        if (d == 2 && x == y)
        {
            cnt++;
            continue;
        }
        int t1 = find(x), t2 = find(y);
        if (t1 == t2)
        {
            int t = (val[y] - val[x] + 3) % 3;
            if (t != d - 1) cnt++;
        }
        else
        {
            par[t2] = t1;
            val[t2] = (val[x] - val[y] + 2 + d) % 3;
        }
    }
    printf("%d\n", cnt);
    return 0;
}