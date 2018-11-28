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
    int n, k;
    cin >> n >> k;
    stack<int> st;
    string s;
    int now = 0;
    for (int i = 0, x; i < k; i++)
    {
        cin >> s;
        if (s[0] == 'u')
        {
            cin >> s;
            x = stoi(s);
            for (int i = 0; i < x; i++)
            {
                int t = -st.top();
                st.pop();
                now = (now + t % n + n) % n;
            }
        }
        else
        {
            x = stoi(s);
            now = (now + x % n + n) % n;
            st.push(x);
        }
    }
    cout << now << endl;
    return 0;
}