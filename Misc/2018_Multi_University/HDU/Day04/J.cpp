#include <bits/stdc++.h>
using namespace std;

const int N = 16;
char s[N][N + 5];
int S[N][N];
int ans;
int dx[] = {0, 0, 0, 0, 4, 4, 4, 4, 8, 8, 8, 8, 12, 12, 12, 12};
int dy[] = {0, 4, 8, 12, 0, 4, 8, 12, 0, 4, 8, 12, 0, 4, 8, 12};

bool r[N][N], c[N][N];

inline void change(int a, int b, int c, int d, int id)
{
    swap(S[dx[id] + (a >> 2)][dy[id] + (a & 3)], S[dx[id] + (b >> 2)][dy[id] + (b & 3)]);
    swap(S[dx[id] + (b >> 2)][dy[id] + (b & 3)], S[dx[id] + (c >> 2)][dy[id] + (c & 3)]);
    swap(S[dx[id] + (c >> 2)][dy[id] + (c & 3)], S[dx[id] + (d >> 2)][dy[id] + (d & 3)]);
}

inline void rotate(int id)
{
    change(0, 12, 15, 3, id);
    change(1, 8, 14, 7, id);
    change(2, 4, 13, 11, id);
    change(5, 9, 10, 6, id);
}

inline bool check(int id)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            int x = dx[id] + i;
            int y = dy[id] + j;
            if (r[x][S[x][y]]) return false;
            if (c[y][S[x][y]]) return false;
        }
    return true;
}

inline void gao(int id, int d)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            int x = dx[id] + i;
            int y = dy[id] + j;
            r[x][S[x][y]] += d;
            c[y][S[x][y]] += d;
        }
}

void dfs(int id, int ans = 0)
{
    // cerr << "dfs :[" << id << " " << ans << "]" << endl;
    if (ans >= ::ans) return;
    if (id == 16) return (void)(::ans = ans);
    for (int i = 0; i < 4; i++)
    {
        if (check(id))
        {
            gao(id, 1);
            dfs(id - 1, ans + i);
            gao(id, -1);
        }
        rotate(id);
    }
}

inline void solve()
{
    ans = 1 << 7;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            S[i][j] = isdigit(s[i][j]) ? s[i][j] - '0' : s[i][j] - 'A' + 10;
    dfs(0);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        for (int i = 0; i < 16; i++) scanf("%s", s[i]);
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));
        solve();
        printf("%d\n", ans);
    }
}
