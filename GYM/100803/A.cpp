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
vector<int> id[2];
vector<int> newid[2];
int n, m;

int solve()
{
    if (id[0].size() != newid[0].size()) return 1000;
    if (id[1].size() != newid[1].size()) return 1000;
    vector<int> a(n);
    for (int i = 0; i < id[0].size(); i++) a[id[0][i]] = newid[0][i];
    for (int i = 0; i < id[1].size(); i++) a[id[1][i]] = newid[1][i];
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[i] < a[j]) cnt++;
    return cnt;
}

int main()
{
    cin >> n >> m;
    vector<int> a(n);
    vector<int> p(m);
    for (auto& t : a) cin >> t;
    for (auto& t : p) cin >> t;
    for (int i = 0; i < n; i++) id[a[i]].push_back(i);
    vector<int> x, y;
    int ans = 1000;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p[i]; j++) x.push_back(i & 1), y.push_back(i & 1 ^ 1);
    for (int i = 0; i < n; i++) newid[x[i]].push_back(i);
    ans = min(ans, solve());
    for (int i = 0; i < 2; i++) newid[i].clear();
    for (int i = 0; i < n; i++) newid[y[i]].push_back(i);
    ans = min(ans, solve());
    cout << ans << endl;
    return 0;
}