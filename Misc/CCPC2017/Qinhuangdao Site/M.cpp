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

typedef PII point;

const int maxn = 105;

inline int dis2(point a) { return a.X * a.X + a.Y * a.Y; }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    point P[maxn];
    scanf("%d", &T);
    while (T--)
    {
        int n, R, r;
        scanf("%d%d%d", &n, &R, &r);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &P[i].X, &P[i].Y);
        vector<int> id;
        vector<PII> ans;
        if (2 * r >= R)
        {
            for (int i = 0; i < n; i++)
            {
                int tmp = dis2(P[i]);
                if (tmp <= (2 * r - R) * (2 * r - R))
                    id.pb(i);
                else
                    ans.pb(mp(tmp, i));
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                int tmp = dis2(P[i]);
                if (tmp <= (R - 2 * r) * (R - 2 * r))
                    id.pb(i);
                else
                    ans.pb(mp(tmp, i));
            }
        }
        if (id.size())
        {
            int tot = id.size();
            printf("%d\n", tot);
            for (int i = 0; i < tot; i++)
                printf("%d%c", id[i] + 1, i == tot - 1 ? '\n' : ' ');
        }
        else
        {
            sort(ans.begin(), ans.end());
            int Ans = ans[0].X;
            for (int i = 0; ans[i].X == Ans; i++)
                id.pb(ans[i].Y);
            int tot = id.size();
            printf("%d\n", tot);
            for (int i = 0; i < tot; i++)
                printf("%d%c", id[i] + 1, i == tot - 1 ? '\n' : ' ');
        }
    }
    return 0;
}
