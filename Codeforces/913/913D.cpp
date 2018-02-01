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

const int N = 1 << 18;
struct pro
{
    int id, limit, time;
    bool operator<(const pro& rhs) const
    {
        return time < rhs.time;
    }
} a[N];

bool vis[N];
int n, T;
bool ok(int m, int n)
{
    int tmp = T;
    int cnt = 0;
    clr(vis, 0);
    for (int i = 0; i < n; i++)
    {
        if (a[i].limit >= m && tmp >= a[i].time)
        {
            cnt++;
            tmp -= a[i].time;
            vis[a[i].id] = 1;
        }
        if (cnt == m) return true;
    }
    return cnt >= m;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    while (~scanf("%d%d", &n, &T))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &a[i].limit, &a[i].time);
            a[i].id = i + 1;
        }
        sort(a, a + n);
        int l = 0, r = n, da;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (ok(mid, n))
                da = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        ok(da, n);
        printf("%d\n%d\n", da, da);
        vector<int> ans;
        for (int i = 1; i <= n; i++)
            if (vis[i]) ans.pb(i);
        for (auto t : ans)
            printf("%d ", t);
        puts("");
    }
    return 0;
}
