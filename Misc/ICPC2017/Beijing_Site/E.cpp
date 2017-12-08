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

const int N = 105;
int c[N];
bool eat[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int m, n, x;
    while (~scanf("%d%d%d", &m, &n, &x))
    {
        for (int i = 0; i < n; i++) scanf("%d", &c[i]);
        sort(c, c + n);
        int p = m, q = 0;
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < n; j++)
                if (i % c[j] == 0)
                {
                    if (p > 0)
                        eat[j] = 1, p--;
                    else
                        eat[j] = 0;
                }
        }
        for (int i = 0; i < n; i++) q += (x % c[i] != 0) && eat[i];
        printf("%d %d\n", p, q);
    }
    return 0;
}
