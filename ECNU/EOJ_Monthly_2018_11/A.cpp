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

void solve(int n)
{
    for (int i = 0; i < 2048; i++)
        for (int j = 0; j < 2048; j++)
            if ((max(i, j) ^ i ^ j) == n)
            {
                printf("%d %d 0 0 0 0\n", i, j);
                return;
            }
    printf("NO\n");
}

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        printf("Case #%d: %d 0 %d 0 0 0\n", ++kase, n, n);
        // solve(n);
    }
    return 0;
}