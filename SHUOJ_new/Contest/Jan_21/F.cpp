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

int cnt[1 << 17];
vector<ll> v, w;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, q;
    while (~scanf("%d%d", &n, &q))
    {
        v.clear();
        clr(cnt, 0);
        ll num;
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &num);
            v.pb(num);
        }
        w = v;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (auto& num : w)
            num = lower_bound(v.begin(), v.end(), num) - v.begin() + 1;
        for (auto& num : w)
            cnt[num]++;
        for (int i = 1; i <= n; i++)
            cnt[i] += cnt[i - 1];
        while (q--)
        {
            static int k;
            scanf("%d", &k);
            printf("%d\n", cnt[k]);
        }
    }
    return 0;
}
