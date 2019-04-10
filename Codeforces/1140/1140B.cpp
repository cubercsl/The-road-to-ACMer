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

const int N = 1 << 7;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        static char s[N];
        scanf("%s", s);
        int x = 0, y = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '>')
                break;
            x++;
        }
        for (int i = n - 1; ~i; i--)
        {
            if (s[i] == '<')
                break;
            y++;
        }
        printf("%d\n", min(x, y));
    }
    return 0;
}