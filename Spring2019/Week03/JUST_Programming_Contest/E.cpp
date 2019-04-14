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

const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        string s, c, p;
        cin >> s >> c >> p;
        map<char, int> dic;
        for (int i = 0; i < 26; i++) dic['a' + i] = INF;
        for (int i = 0; i < n; i++)
        {
            auto a = s[i];
            auto b = c[i] - '0';
            dic[a] = min(b, dic[a]);
        }
        long long ans = 0;
        for (auto&& t : p) ans += dic[t];
        if (ans >= INF) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}