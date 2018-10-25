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
    map<int, int> t;
    int q;
    scanf("%d", &q);
    int l = 0, r = 0;
    char op[5];
    for (int i = 0, id; i < q; i++)
    {
        scanf("%s%d", op, &id);
        if (i == 0)
        {
            t[id] = 0;
            l--;
            r++;
        }
        else if (op[0] == 'L')
        {
            t[id] = l;
            l--;
        }
        else if (op[0] == 'R')
        {
            t[id] = r;
            r++;
        }
        else
        {

            int ans = min(t[id] - l - 1, r - t[id] - 1);
            printf("%d\n", ans);
        }
    }
    return 0;
}