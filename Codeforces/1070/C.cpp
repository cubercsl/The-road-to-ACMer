#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(args...)                             \
    do                                           \
    {                                            \
        cout << "\033[32;1m" << #args << " -> "; \
        err(args);                               \
    } while (0)
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/

typedef long long ll;
const int N = 1 << 20;
vector<pair<int, int>> in[N], out[N];
ll cnt[N << 2], sum[N << 2];

void update(int p, int v, int l, int r, int o)
{
    // dbg(p, v);
    cnt[o] += v;
    sum[o] += 1LL * p * v;
    if (l == r) return;
    const int m = l + r >> 1;
    if (p <= m)
        update(p, v, l, m, o << 1);
    else
        update(p, v, m + 1, r, o << 1 | 1);
}

ll query(int k, int l, int r, int o)
{
    if (l == r) return 1LL * l * min(1LL * k, sum[o]);
    const int m = l + r >> 1;
    if (cnt[o << 1] >= k) return query(k, l, m, o << 1);
    return query(k - cnt[o << 1], m + 1, r, o << 1 | 1) + sum[o << 1];
}

int main()
{
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 0, l, r, c, p; i < m; i++)
    {
        scanf("%d%d%d%d", &l, &r, &c, &p);
        in[l].emplace_back(p, c);
        out[r].emplace_back(p, -c);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (auto& t : in[i]) update(t.first, t.second, 1, N, 1);
        ans += query(k, 1, N, 1);
        dbg(ans);
        for (auto& t : out[i]) update(t.first, t.second, 1, N, 1);
    }
    printf("%lld\n", ans);
    return 0;
}