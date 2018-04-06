#include <bits/stdc++.h>
using namespace std;

const int N = 505;
char s[N][N];
int n, m;
int dx[] = {-1, 0 ,1 , 0};
int dy[] = {0, -1, 0, 1};

bool dfs(int x, int y)
{
    if(x < 0 || y < 0 || x >= n || y >= m || s[x][y] == 'x') return false;
    if(s[x][y] == 't') return true;
    s[x][y] = 'x';
    for(int i = 0; i < 4; i++)
        if(dfs(x + dx[i], y + dy[i])) return true;
    return false;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) scanf("%s", s[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (s[i][j] == 's') puts(dfs(i, j) ? "YES" : "NO");
    }
    return 0;
}