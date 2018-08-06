#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
char s[N];
int x, y;
int dp[N][15];
int n, ans;
pair<int, int> p;
void dfs(int& l, int& r, int u, int mx)
{
    if (u == 0)
        return;
    int pos = (mx <= x) ? (mx) : (mx <= y + 1 ? (y - (mx - x - 1)) : mx - 2);
    if (s[u] == pos)
    {
        if (dp[u][mx] == dp[u - 1][mx] + 1)
            dfs(l, r, u - 1, mx);
        else
        {
            if (mx == 2 + y) r = u;
            if (mx == x + 1) l = u + 1;
            dfs(l, r, u, mx - 1);
        }
    }
    else
    {
        if (dp[u][mx] == dp[u - 1][mx])
            dfs(l, r, u - 1, mx);
        else
        {
            if (mx == 2 + y) r = u;
            if (mx == x + 1) l = u + 1;
            dfs(l, r, u, mx - 1);
        }
    }
}

void gao(int x, int y)
{ // 换x和y
    ::x = x, ::y = y;
    memset(dp[0], 0, sizeof(dp[0]));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 12; j++)
        {
            int tmp;
            if (j <= x)
                tmp = j;
            else if (j <= y + 1)
                tmp = y - (j - x - 1);
            else
                tmp = j - 2;
            if (s[i] == tmp)
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j] + 1);
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    int l = 1, r = 1;
    if (dp[n][11] <= ans) return;
    int mx = 11;
    dfs(l, r, n, mx);
    ans = dp[n][11];
    p = {l, r};
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ans = 0;
        scanf("%d", &n);
        scanf("%s", s + 1);
        for (int i = 1; i <= n; i++) s[i] -= '0';
        for (int i = 0; i < 10; i++)
            for (int j = i + 1; j < 10; j++)
                gao(i, j);
        printf("%d %d %d\n", ans, p.first, p.second);
    }
}