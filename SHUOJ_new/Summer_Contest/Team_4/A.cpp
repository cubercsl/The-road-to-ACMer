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
const double eps = 1e-6;

const int maxn = 105;
int a[maxn];
int tmp[100000];
int vis[100000];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", a + i);
        sort(a, a + n);
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            if (i != n - 1)
            {
                s.insert(a[i]);
                s.insert(2 * a[i]);
                s.insert(3 * a[i]);
            }
            else
            {
                s.insert(a[i]);
                s.insert(2 * a[i]);
            }
        }
        vector<int> v;
        for (auto& t : s)
            v.pb(t);
        int tot = v.size();
        clr(vis, 0);
        clr(tmp, 0);
        tmp[0] = 1;
        vis[0] = 1;
        for (int i = 1; i <= k; i++)
        {
            for (int j = 0; j <= v[tot - 1] * i; j++)
                for (auto& t : v)
                    if (vis[j]) tmp[j + t] = 1;
            for (int j = 0; j <= v[tot - 1] * i; j++)
                vis[j] = tmp[j];
        }
        int cnt = 0;
        for (int i = 0; i <= v[tot - 1] * k; i++)
            if (vis[i]) cnt++;
        printf("Scenario #%d:\n%d\n\n", ++kase, cnt);
    }
    return 0;
}
