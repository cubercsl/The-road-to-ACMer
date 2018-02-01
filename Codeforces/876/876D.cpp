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

const int maxn = 300005;
int n;
int v[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (cin >> n)
    {
        int p;
        int l = n;
        int d = 0;
        clr(v, 0);
        printf("1");
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &p);
            v[p] = 1;
            while (v[l] && l) l--, d++;
            printf(" %d", i - d + 1);
        }
        puts("");
    }
    return 0;
}
