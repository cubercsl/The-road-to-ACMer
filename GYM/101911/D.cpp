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

unordered_map<int, vector<int>> dic;

int main()
{
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> ans(n);
    for (int i = 0, x; i < n; i++)
    {
        scanf("%d", &x);
        dic[x].push_back(i);
    }
    for (auto& t : dic)
    {
        int x = t.first;
        int d = 0;
        int m = t.second.size();
        for (int i = 1; i * i <= x; i++)
        {
            if (x % i) continue;
            if (i * i != x)
            {
                if (d < m) ans[t.second[d++]] = {i, x / i};
                if (d < m) ans[t.second[d++]] = {x / i, i};
            }
            else if (d < m)
                ans[t.second[d++]] = {i, i};
        }
        if (d != m) return puts("NO"), 0;
    }
    puts("YES");
    for (int i = 0; i < n; i++) printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}