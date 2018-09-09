// ybmj
#include <bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define lson_len (len - (len >> 1))
#define rson_len (len >> 1)
#define pb(x) push_back(x)
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define my_unique(a) a.resize(distance(a.begin(), unique(a.begin(), a.end())))
#define my_sort_unique(c) (sort(c.begin(), c.end())), my_unique(c)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const int maxn = 1e5 + 5;
map<pii, int> ID;
vector<int> G[maxn];

int work(int id)
{
    int ret = 0;
    int cnt = 0;
    int last = -1;
    for (auto& v : G[id])
    {
        if (v == last) continue;
        if (v == last + 1)
        {
            cnt++;
            last = v;
        }
        else
        {
            ret = max(ret, cnt);
            cnt = 1;
            last = v;
        }
    }
    return max(ret, cnt);
}
int main()
{
// /*
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    // */
    std::ios::sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        ID.clear();
        for (int i = 0; i < maxn; i++) G[i].clear();
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            int k;
            scanf("%d", &k);
            for (int j = 0, x, y; j < k; j++)
            {
                scanf("%d%d", &x, &y);
                pii tmp = mp(x, y);
                if (ID[tmp] == 0) ID[tmp] = ++cnt;
                int id = ID[tmp];
                G[id].pb(i);
            }
        }
        int ans = 0;
        for (int i = 1; i <= cnt; i++)
        {
            ans = max(ans, work(i));
        }
        printf("%d\n", ans);
    }
}