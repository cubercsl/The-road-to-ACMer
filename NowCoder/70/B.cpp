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

vector<ll> v;

void dfs(int pos, ll now)
{
    if (pos > 10) return;
    v.pb(now);
    dfs(pos + 1, now * 10 + 4);
    dfs(pos + 1, now * 10 + 7);
}

int search(ll val)
{
    int l = 0, r = v.size(), pos = -1;
    while (l <= r)
    {
        int m = l + r >> 1;
        if (v[m] >= val)
            pos = m, r = m - 1;
        else
            l = m + 1;
    }
    assert(~pos);
    return pos;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    dfs(0, 0);
    sort(v.begin(), v.end());
    // for (auto& t : v)
    // cout << t << endl;
    int l, r;
    while (cin >> l >> r)
    {
        int lpos = search(l);
        int rpos = search(r);
        ll ans = 0;
        for (int i = lpos; i < rpos; i++)
        {
            ans += v[i] * (v[i] - l + 1);
            l = v[i] + 1;
        }

        ans += v[rpos] * (r - l + 1);
        cout << ans << endl;
    }
    return 0;
}