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

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> a;
        for (int i = 0, u, v; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            --u, --v;
            if (u == 0) a.push_back(v);
            if (v == 0) a.push_back(u);
        }
        sort(a.begin(), a.end());
        vector<int> ans(1<< n);
        ans[0] = 0;
        int id = 1;
        for (auto& u : a)
        {
            ans[u] = id;
            id <<= 1;
        }
        id = 3;
        for (int i = 1; i < (1 << n); i++)
        {
            if (ans[i]) continue;
            ans[i] = id;
            id++;
            if ((id & (id - 1)) == 0) id++;
        }
        for (int i = 0; i < (1 << n); i++) printf("%d%c", ans[i], " \n"[i == (1 << n) - 1]);
    }

    return 0;
}