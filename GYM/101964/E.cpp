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
    int n, m, l;
    scanf("%d%d%d", &n, &m, &l);
    vector<pair<int, int>> vec;
    for (int i = 0, x, y; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        if (l < y) continue;
        vec.emplace_back(x + y - l, 1);
        vec.emplace_back(x - y + l + 1, -1);
    }
    sort(vec.begin(), vec.end());
    int now = 0;

    vector<pair<int, int>> query;
    for (int i = 0, x; i < m; i++)
    {
        scanf("%d", &x);
        query.emplace_back(x, i);
    }
    vector<int> ans(m);
    sort(query.begin(), query.end());
    for (int i = 0, j = 0; i < m; i++)
    {
        for (; j < vec.size() && vec[j].first <= query[i].first; j++) now += vec[j].second;
        ans[query[i].second] = now;
    }
    for (auto& t : ans) printf("%d\n", t);
}