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

const int N = 1 << 10;

int w[N], d[N], c[N];

vector<int> G[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", w + i);
    for (int i = 1, u, v; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    memset(d, -1, sizeof(d));
    queue<int> q;
    d[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto& v : G[u])
        {
            if (~d[v]) continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    for (int i = 1; i <= n; i++)
        if (w[i]) c[d[i]] ^= 1;
    int ans = 0;
    for (int i = 0; i < N; i++) ans += c[i];
    puts(ans ? "First" : "Second");
    return 0;
}