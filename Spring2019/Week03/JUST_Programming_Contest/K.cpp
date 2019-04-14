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
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        vector<int> a(n + 1);
        set<int> ans;
        vector<vector<int>> f(n + 1, vector<int>(30));
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                if (a[i] >> j & 1)
                    f[i][j] = i;
                else
                    f[i][j] = f[i - 1][j];
            }
            int x = a[i];
            int j = i - 1;
            ans.insert(x);
            for (int j = i - 1; j;)
            {
                int nxt = 0;
                for (int l = 0; l < 30; l++)
                {
                    if (x >> l & 1) continue;
                    nxt = max(nxt, f[j][l]);
                }
                if (nxt == 0) break;
                x |= a[nxt];
                ans.insert(x);
                j = nxt - 1;
            }
        }
        printf("%d\n", static_cast<int>(ans.size()));
    }
    return 0;
}