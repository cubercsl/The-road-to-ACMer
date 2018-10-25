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

typedef pair<int, int> PII;
#define X first
#define Y second
#define mp make_pair
int tu[5][5];
set<int> ans[5][5][5];
void prin()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}

int gao()
{
    int ans = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            ans = ans * 3 + tu[i][j] + 1;
    return ans;
}

bool check()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 2; j++)
        {
            if (tu[i][j] != -1)
            {
                if (tu[i][j] == tu[i][j + 1] && tu[i][j + 1] == tu[i][j + 2])
                    return true;
            }
            if (tu[j][i] != -1)
            {
                if (tu[j][i] == tu[j + 1][i] && tu[j][i] == tu[j + 2][i])
                    return true;
            }
        }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (tu[i][j] != -1)
            {
                if (tu[i][j] == tu[i + 1][j + 1] && tu[i][j] == tu[i + 2][j + 2])
                    return true;
            }
    for (int i = 3; i > 1; i--)
        for (int j = 0; j < 2; j++)
            if (tu[i][j] != -1)
            {
                if (tu[i][j] == tu[i - 1][j + 1] && tu[i][j] == tu[i - 2][j + 2])
                    return true;
            }
    return false;
}
void dfs(int id, PII u, int cnt)
{
    // dbg(cnt, u.first, u. second);
    if (cnt == 16)
    {
        if (check())
            ans[id][u.X][u.Y].insert(gao());
        return;
    }
    if (cnt > 2)
    {
        if (cnt & 1)
        {
            if (check()) return;
        }
        else
        {
            if (check())
            {
                ans[id][u.X][u.Y].insert(gao());
                return;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        int x = 0;
        while (tu[x][i] != -1) x++;
        if (x < 4)
        {
            tu[x][i] = (cnt + 1) & 1;
            dfs(id, mp(x, i), cnt + 1);
            tu[x][i] = -1;
        }
    }
}
int main()
{
    memset(tu, -1, sizeof(tu));
    for (int i = 0; i < 4; i++)
    {
        tu[0][i] = 1;
        dfs(i, mp(0, i), 1);
        tu[0][i] = -1;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                printf("%d,", ans[i][j][k].size());
    }
}
