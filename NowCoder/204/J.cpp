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
    int n, m;
    scanf("%d%d", &n, &m);
    int id;
    vector<int> ans(n + 1, 1);
    string last, s;
    for (int i = 0, id; i < m; i++)
    {
        cin >> id >> s;
        if (s != last) ans[id] = 0;
        last = s;
    }
    vector<int> buf;
    for (int i = 1; i <= n; i++)
        if (ans[i]) buf.push_back(i);
    int t = buf.size();
    for (int i = 0; i < t; i++)
        printf("%d%c", buf[i], " \n"[i == t - 1]);
    return 0;
}