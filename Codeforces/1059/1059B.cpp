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

const int N = 1 << 10;
char s[N][N];
char t[N][N];

int tx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ty[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    memset(t, '.', sizeof(t));
    for (int i = 2; i < n; i++)
        for (int j = 2; j < m; j++)
        {
            bool flag = true;
            for (int k = 0; k < 8; k++)
                if (s[i + tx[k]][j + ty[k]] != '#')
                {
                    flag = false;
                    break;
                }
            if (flag)
                for(int k = 0; k < 8; k++)
                    t[i + tx[k]][j + ty[k]] = '#';
        }
    for (int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if (s[i][j] != t[i][j])
                return puts("No"), 0;
    puts("Yes");
    return 0;
}