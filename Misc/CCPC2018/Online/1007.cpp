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
const int maxn = 2e4 + 5;
ll a[maxn], pre[maxn * 2];
bool vis[maxn];
ll n, s, m, k;

ll solve(vector<int> tmp, int len) {
    ll ret = 0;
    ll sz = tmp.size();
    for (int i = 1; i <= sz; i++) pre[i] = pre[i - 1] + a[tmp[i - 1]];
    deque<int> dq;
    for (int i = 0; i < sz; i++) {
        while (dq.size() && (i + 1) - dq.front()  > len) dq.pop_front();
        while (dq.size() && pre[dq.back()] > pre[i + 1]) dq.pop_back();
        dq.push_back(i + 1);
        ret = max(ret, pre[i + 1] - pre[dq.front()]);
    }
    return ret;
}
ll work(int s) {
    ll sum = 0;
    vector<int> tmp;
    while (!vis[s]) {
        sum += a[s];
        vis[s] = 1;
        tmp.pb(s);
        s = (s + k) % n;
    }
    ll sz = tmp.size();
    for (int i = 0; i < sz; i++) {
        tmp.pb(tmp[i]);
    }
    ll ret = 0;
    ll Max = 0;
    // 1
    if (sum > 0) {
        ll foo = m - (m / sz) * sz;
        Max += (m / sz) * sum;
        Max += solve(tmp, foo);
        ret = max(ret, Max);
    }
    // 2
    if (sum > 0 && m / sz > 0) {
        Max = (m / sz - 1) * sum;
        
        Max += solve(tmp, sz);
        ret = max(ret, Max);
    }
    // 3
    ret = max(ret, solve(tmp, min(m, sz)));
    return ret;
}
int main() {
// /*
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    // */
    std::ios::sync_with_stdio(false);
    int T, kase = 1;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld%lld", &n, &s, &m, &k);
        for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
        for (int i = 0; i < n; i++) vis[i] = 0;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) ans = max(ans, work(i));
        }
        printf("Case #%d: %lld\n", kase++, max(s - ans, 0LL));
    }
}