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
#include <ext/rope>
using namespace __gnu_cxx;
const int N = 1 << 18;
rope<int> a[N];

int fa[N];
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) fa[i] = i, a[i].push_back(i);
    for (int i = 0, x, y; i < n - 1; i++)
    {
        scanf("%d%d", &x, &y);
        x = find(x), y = find(y);
        a[x] += a[y];
        fa[y] = x;
    }
    for (int i = 1; i <= n; i++)
        if (find(i) == i)
        {
            for (int j = 0; j < a[i].size(); j++)
                printf("%d ", a[i][j]);
        }
    return 0;
}