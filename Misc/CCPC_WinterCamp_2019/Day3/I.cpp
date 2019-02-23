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

const int N = 1 << 18;

pair<int, pair<int, int>> Node;


const int mod = 119 << 23 | 1;
typedef long long ll;
ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

ll p1_3[N];
ll p2_3[N];
int main()
{
    ll inv3 = Pow(3, mod - 2);
    p1_3[0] = p2_3[0] = 1;
    for (int i = 1; i < N; i++)
        p1_3[i] = p1_3[i - 1] * inv3 % mod;
    for (int i = 1; i < N; i++)
        p2_3[i] = p2_3[i - 1] * 2 % mod * inv3 % mod;
    int n, m;
    scanf("%d%d", &n, &m);
    ll pow3 = Pow(3, n);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= n; i++) p[i].push_back(cnt + i);
    while (m--)
    {
        static int op, x, y;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d%d", &x, &y);
            unite(x, y);
        }
        else
        {
            scanf("%d", &x);
            x = find(x);
            int home = cnt[x].second + lazy[x].second;
            int away = cnt[x].first + lazy[x].first - home;
            dbg(home, away);
            ll ans = p2_3[home] * p1_3[away] % mod * pow3 % mod;
            printf("%lld\n", ans);
        }
    }
    return 0;
}