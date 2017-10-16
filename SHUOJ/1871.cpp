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

const int maxn = 2e5 + 5;
int par[maxn], val[maxn];
void init(int n)
{
    for (int i = 0; i <= n; i++)
        par[i] = i, val[i] = 0;
}

int find(int x)
{
    if (par[x] == x) return x;
    int tmp = find(par[x]);
    val[x] += val[par[x]];
    return par[x] = tmp;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        init(n);
        int l, r, s;
        bool flag = true;
        while (m--)
        {
            scanf("%d%d%d", &l, &r, &s);
            l--;
            int t1 = find(l);
            int t2 = find(r);
            if (t1 != t2)
            {
                par[t2] = t1;
                val[t2] = val[l] - val[r] + s;
            }
            else if (val[r] - val[l] != s)
                flag = false;
        }
        puts(flag ? "Unknown!" : "Error!");
    }

    return 0;
}
