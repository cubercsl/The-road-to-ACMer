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
    mt19937 mt_rand(time(0));
    int n;
    cin >> n;
    int ans;
    string s;
    for (;;)
    {
        s = "";
        for (int i = 0; i < n; i++) s.push_back('0' + (mt_rand() & 1));
        cout << s << endl;
        cin >> ans;
        if (ans == n) return 0;
        if (ans == n / 2) break;
    }
    string ret = s;
    s[0] = s[0] ^ 1;
    for (int i = 1; i < n; i++)
    {
        string t = s;
        t[i] = t[i] ^ 1;
        cout << t << endl;
        cin >> ans;
        if (ans) ret[i] ^= 1;
    }
    cout << ret << endl;
    cin >> ans;
    if (ans == n) return 0;
    for (auto& t : ret) t ^= 1;
    cout << ret << endl;
    cin >> ans;
    assert(ans == n);
    return 0;
}