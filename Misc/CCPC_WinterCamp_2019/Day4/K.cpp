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

const int N = 1 << 17;
vector<int> G[N];

long long dp[N], a[N];

void dfs(int u, int fa)
{
    dp[u] = a[u];
    for (auto& v : G[u])
    {
        if (v == fa) continue;
        dfs(v, u);
        dp[u] = max(dp[u], dp[v] + a[u]);
    }
}

inline int getval(int x)
{
    if (x > 0) return 1 << (x - 1);
    if (x < 0) return (1 << (-x - 1)) * (-1);
    return 0;
}

void print(long long x)
{
    if (x < 0) putchar('-'), x = -x;
    static short stk[100];
    int top = 0;
    do
        stk[++top] = x & 1;
    while (x >>= 1);
    while (top) putchar('0' + stk[top--]);
    puts("");
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    for (int i = 1; i <= n; i++) a[i] = getval(a[i]);
    for (int i = 1; i <= n; i++) dbg(a[i]);
    for (int i = 1, u, v; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        static int x;
        memset(dp, 0xc0, sizeof(dp));
        scanf("%d", &x);
        vector<long long> vec;
        for (auto& u : G[x])
        {
            dfs(u, x);
            vec.push_back(dp[u]);
        }
        sort(vec.begin(), vec.end(), greater<long long>());
        long long ans = a[x];
        vec.resize(4);
        for (int i = 0; i < 4; i++) ans += max(vec[i], 0LL);
        dbg(ans);
        print(ans);
    }
    return 0;
}