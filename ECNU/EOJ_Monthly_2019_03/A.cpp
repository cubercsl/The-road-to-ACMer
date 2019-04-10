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

vector<tuple<int, int, int>> ans;

void dfs(int l, int r, int offset)
{
    if ((r - l) / 3 == 1)
    {
        ans.emplace_back(l + 0, l + 1 + offset, l + 2 + offset * 2);
        return;
    }
    if ((r - l) / 3 == 2)
    {
        ans.emplace_back(l + 0, l + 2 + offset, l + 3 + offset * 2);
        ans.emplace_back(l + 1, l + 4 + offset, l + 5 + offset * 2);
        return;
    }
    if ((r - l) / 3 == 3)
    {
        ans.emplace_back(l + 0, l + 3 + offset, l + 4 + offset * 2);
        ans.emplace_back(l + 1, l + 5 + offset, l + 6 + offset * 2);
        ans.emplace_back(l + 2, l + 7 + offset, l + 8 + offset * 2);
        return;
    }
    int len = (r - l) / 3;

    for (int i = 0; i < len; i++)
        ans.emplace_back(l + len / 2 + i, len * 2 + i + offset, len * 5 / 2 + i + offset * 2);
    dfs(l, l + len / 2, 0);
    dfs(l + len, l + len * 3 / 2, len / 2);
    dfs(l + len * 2, l + len * 5 / 2, len / 2);
}

int main()
{
    int n;
    cin >> n;
    dfs(0, n * 3);

    return 0;
}