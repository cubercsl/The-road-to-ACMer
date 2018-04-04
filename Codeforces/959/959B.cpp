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

const int maxn = 1 << 17;
string s[maxn];
int a[maxn], cost[maxn];
map<string, int> mp;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    clr(cost, 0x3f);
    for (int i = 0; i < k; i++)
    {
        int t;
        cin >> t;
        while (t--)
        {
            int ind;
            cin >> ind, ind--;
            cost[i] = min(cost[i], a[ind]);
            mp[s[ind]] = i;
        }
    }
    ll ans = 0;
    while (m--)
    {
        string t;
        cin >> t;
        ans += cost[mp[t]];
    }
    cout << ans << endl;
    return 0;
}
