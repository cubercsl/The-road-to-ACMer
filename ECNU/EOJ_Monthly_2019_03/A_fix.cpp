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

void dfs(vector<int> a)
{
    int n = a.size() / 3;
    if (n == 1)
    {
        ans.emplace_back(a[0], a[1], a[2]);
        return;
    }
    if (n == 2)
    {
        ans.emplace_back(a[0], a[2], a[3]);
        ans.emplace_back(a[1], a[4], a[5]);
        return;
    }
    if (n == 3)
    {
        ans.emplace_back(a[0], a[3], a[4]);
        ans.emplace_back(a[1], a[5], a[6]);
        ans.emplace_back(a[2], a[7], a[8]);
        return;
    }

    for (int i = 0; i < (n + 1) / 2; i++)
        ans.emplace_back(a[n / 2 + i], a[n + n / 2 * 2 + i], a[n + n / 2 * 2 + (n + 1) / 2 + i]);
    vector<int> tmp;
    for (int i = 0; i < n / 2; i++) tmp.push_back(a[i]);
    for (int i = 0; i < n / 2; i++) tmp.push_back(a[n + i]);
    for (int i = 0; i < n / 2; i++) tmp.push_back(a[n + n / 2 + i]);
    dfs(tmp);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n * 3);
    iota(a.begin(), a.end(), 2);
    dfs(a);
    for (auto& e : ans)
    {
        static int a, b, c;
        tie(a, b, c) = e;
        cout << a << ' ' << b << ' ' << c << '\n';
    }
    return 0;
}