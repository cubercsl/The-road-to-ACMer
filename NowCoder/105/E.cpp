#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
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
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<PII> a(n);
        for (auto& t : a) scanf("%d%d", &t.X, &t.Y);
        sort(a.begin(), a.end());
        for (int i = 1; i < n; i++) a[i].Y = max(a[i].Y, a[i - 1].Y);
        a.erase(unique(a.begin(), a.end()), a.end());
        while (m--)
        {
            static int t;
            scanf("%d", &t);
            int pos = upper_bound(a.begin(), a.end(), make_pair(t, INF)) - a.begin() - 1;
            if (~pos)
                printf("%d\n", a[pos].Y);
            else
                printf("0\n");
        }
    }
    return 0;
}