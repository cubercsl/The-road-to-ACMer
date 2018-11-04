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

map<string, int> dic;

int main()
{
    dic["bool"] = 1;
    dic["char"] = 1;
    dic["int"] = 4;
    dic["float"] = 4;
    dic["long"] = 8;
    dic["double"] = 8;
    dic["__int128"] = 16;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, kase = 0;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        string type, size;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> type;
            int tmp = 0;
            tmp += dic[type];
            if (type == "long")
            {
                cin >> type;
                if (type == "double") tmp += dic[type];
            }
            cin >> size;
            int pos = size.find('[');
            if (~pos)
            {
                size = size.substr(pos + 1);
                size = size.substr(0, size.size() - 2);
                dbg(size);
                int x = stoi(size);
                dbg(x);
                tmp *= x;
                dbg(tmp);
            }
            ans += tmp;
        }
        cout << "Case #" << ++kase << ": " << (ans + 1023) / 1024 << endl;
    }
    return 0;
}