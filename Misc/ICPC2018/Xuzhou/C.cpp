// ybmj
#include <bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define lson_len (len - (len >> 1))
#define rson_len (len >> 1)
#define pb(x) push_back(x)
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define my_unique(a) a.resize(distance(a.begin(), unique(a.begin(), a.end())))
#define my_sort_unique(c) (sort(c.begin(), c.end())), my_unique(c)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
map<int, double> val;
pii in[25] = {{6, 10000}, {7, 36}, {8, 720}, {9, 360}, {10, 80}, {11, 252}, {12, 108}, {13, 72}, {14, 54}, {15, 180}, {16, 72}, {17, 180}, {18, 119}, {19, 36}, {20, 360}, {21, 1080}, {22, 144}, {23, 1800}, {24, 3600}};
bool vis[15];
char maze[5][5];
int tp[5][5];
int G[5][5];
vector<pii> star, sharp;
vector<int> num;
double ans, res;
int cnt, CNT;

int row(int r)
{
    int ret = 0;
    for (int i = 0; i < 3; i++)
    {
        if (tp[r][i] == 2) ret++;
    }
    return ret;
}
int col(int c)
{
    int ret = 0;
    for (int i = 0; i < 3; i++)
    {
        if (tp[i][c] == 2) ret++;
    }
    return ret;
}
int dig()
{
    int ret = 0;
    for (int i = 0; i < 3; i++)
    {
        if (tp[i][i] == 2) ret++;
    }
    return ret;
}
int rdig()
{
    int ret = 0;
    for (int i = 0; i < 3; i++)
    {
        if (tp[i][2 - i] == 2) ret++;
    }
    return ret;
}

void solve_r(int r, int i, int tmp)
{
    if (i == 3)
    {
        cnt++;
        res += val[tmp];
        return;
    }
    if (tp[r][i] != 2)
    {
        solve_r(r, i + 1, tmp + G[r][i]);
    }
    else
    {
        for (auto& v : num)
        {
            if (!vis[v])
            {
                vis[v] = 1;
                solve_r(r, i + 1, tmp + v);
                vis[v] = 0;
            }
        }
    }
}
void solve_c(int c, int i, int tmp)
{
    if (i == 3)
    {
        cnt++;
        res += val[tmp];
        return;
    }
    if (tp[i][c] != 2)
    {
        solve_c(c, i + 1, tmp + G[i][c]);
    }
    else
    {
        for (auto& v : num)
        {
            if (!vis[v])
            {
                vis[v] = 1;
                solve_c(c, i + 1, tmp + v);
                vis[v] = 0;
            }
        }
    }
}
void solve_d(int i, int tmp)
{
    if (i == 3)
    {
        cnt++;
        res += val[tmp];
        return;
    }
    if (tp[i][i] != 2)
    {
        solve_d(i + 1, tmp + G[i][i]);
    }
    else
    {
        for (auto& v : num)
        {
            if (!vis[v])
            {
                vis[v] = 1;
                solve_d(i + 1, tmp + v);
                vis[v] = 0;
            }
        }
    }
}
void solve_rd(int i, int tmp)
{
    if (i == 3)
    {
        cnt++;
        res += val[tmp];
        return;
    }
    if (tp[i][2 - i] != 2)
    {
        solve_rd(i + 1, tmp + G[i][2 - i]);
    }
    else
    {
        for (auto& v : num)
        {
            if (!vis[v])
            {
                vis[v] = 1;
                solve_rd(i + 1, tmp + v);
                vis[v] = 0;
            }
        }
    }
}

void work()
{
    double fuck = 0;
    // choose number
    for (int i = 0; i < 3; i++)
    {
        res = 0;
        cnt = 0;
        solve_r(i, 0, 0);
        res = res / cnt;
        fuck = max(fuck, res);

        res = 0;
        cnt = 0;
        solve_c(i, 0, 0);
        res = res / cnt;
        fuck = max(fuck, res);
    }
    res = 0;
    cnt = 0;
    solve_d(0, 0);
    res = res / cnt;
    fuck = max(fuck, res);

    res = 0;
    cnt = 0;
    solve_rd(0, 0);
    res = res / cnt;
    fuck = max(fuck, res);

    ans += fuck;
}

void dfs(int pos)
{
    if (pos == star.size())
    {
        CNT++;
        work();
        return;
    }
    int r = star[pos].first;
    int c = star[pos].second;
    for (auto& v : num)
    {
        if (!vis[v])
        {
            vis[v] = 1;
            G[r][c] = v;
            dfs(pos + 1);
            vis[v] = 0;
        }
    }
}
int main()
{
// /*
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    // */
    std::ios::sync_with_stdio(false);
    for (int i = 0; i < 19; i++) val[in[i].first] = in[i].second;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        for (int i = 0; i < 3; i++) scanf("%s", maze[i]);
        clr(vis, 0);
        clr(tp, 0);
        star.clear();
        sharp.clear();
        num.clear();
        for (int i = 0; i < 3; i++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (maze[i][k] == '*')
                {
                    tp[i][k] = 1;
                    star.pb(mp(i, k));
                }
                else if (maze[i][k] == '#')
                {
                    tp[i][k] = 2;
                    sharp.pb(mp(i, k));
                }
                else
                {
                    G[i][k] = maze[i][k] - '0';
                    vis[maze[i][k] - '0'] = 1;
                }
            }
        }
        for (int i = 1; i <= 9; i++)
        {
            if (!vis[i]) num.pb(i);
        }
        ans = 0;
        CNT = 0;
        dfs(0);
        printf("%.5lf\n", ans / CNT);
    }
}