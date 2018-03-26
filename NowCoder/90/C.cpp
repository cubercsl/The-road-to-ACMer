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

const int maxn = 1000005;
vector<int> q;
ll ave[maxn], a[maxn], b[maxn];
bool vis[maxn];
ll solve(int sz, int i)
{
    ll ans = 0;
    b[0] = 0;
    for (int j = 0; j < sz - 1; j++) b[j + 1] = b[j] + a[q[j]] - ave[i];
    sort(b, b + sz);
    ll x = b[sz / 2];
    for (int j = 0; j < sz; j++) ans += abs(x - b[j]);
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    k++;
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    if (k >= n)
    {
        ll tmp = a[0];
        for (int i = 1; i < n; i++)
            if (tmp != a[i]) {
                printf("gg\n");
                return 0;
            }
        printf("0\n");
        return 0;
    }
    bool flag = 1;
    ll ans = 0;
    for (int i = 0; i < k; i++)
        if (!vis[i])
        {
            int j = i;
            while (!vis[j]) vis[j] = 1, q.push_back(j), ave[i] += a[j], j = (j + k) % n;
            int sz = q.size();
            if (ave[i] % sz)
            {
                flag = 0;
                break;
            }
            ave[i] /= sz;
            if (i && ave[i] != ave[i - 1])
            {
                flag = 0;
                break;
            }
            ans += solve(sz, i);
            q.clear();
        }
    if (!flag)
        printf("gg\n");
    else
        printf("%lld\n", ans);
    return 0;
}