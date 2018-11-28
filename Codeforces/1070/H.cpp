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

const int N = 1 << 14;
string s[N];
unordered_map<string, int> id;
unordered_map<string, int> cnt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        unordered_set<string> buf;
        for (int j = 0; j < s[i].length(); j++)
            for (int k = 1; j + k - 1 < s[i].length(); k++)
                buf.insert(s[i].substr(j, k));
        for (auto& t : buf) id[t] = i, cnt[t]++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        static string ss;
        cin >> ss;
        int ans = cnt[ss];
        cout << ans << " ";
        if (ans == 0)
            cout << "-\n";
        else
            cout << s[id[ss]] << "\n";
    }
    return 0;
}