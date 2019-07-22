#include <bits/stdc++.h>
using namespace std;

const int N = 128;
const int mod = 119 << 23 | 1;
struct Trie
{
    int ch[N][2];
    int f[N], val[N];
    int sz, rt;
    int newNode()
    {
        memset(ch[sz], -1, sizeof(ch[sz])), val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, rt = newNode(); }
    inline int idx(char c) { return c - '0'; }
    void insert(const char* s, int x)
    {
        int u = rt;
        for (int i = 0; s[i]; i++)
        {
            int c = idx(s[i]);
            if (!~ch[u][c]) ch[u][c] = newNode();
            u = ch[u][c];
        }
        val[u] |= 1 << x;
    }
    void build()
    {
        queue<int> q;
        f[rt] = rt;
        for (int c = 0; c < 2; c++)
        {
            if (~ch[rt][c])
                f[ch[rt][c]] = rt, q.push(ch[rt][c]);
            else
                ch[rt][c] = rt;
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            val[u] |= val[f[u]];
            for (int c = 0; c < 2; c++)
            {
                if (~ch[u][c])
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
    }
    int go(const char* str, int len)
    {

        int u = rt;
        int ans = 0;
        for (int i = 0; i < len; ++i)
            u = ch[u][str[i] - '0'], ans |= val[u];
        return ans;
    }
} ac[2];

// 0 正串 1反串

char s[N];
int mask[20][1 << 20];

char ms[40];
int gen(int i, int j)
{

    for (int k = 0; k < i; ++k)
        ms[k] = bool(j & (1 << k)) + '0', ms[i * 2 - k - 1] = !bool(j & (1 << k)) + '0';
    return ac[0].go(ms, i * 2);
}

int dp[105][N][N][1 << 6];
int tmp[105][1 << 6];

inline void update(int& x, int y)
{
    if ((x += y) >= mod) x -= mod;
}

void fwt(int f[], int m)
{
    int n = __builtin_ctz(m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (j & (1 << i))
                update(f[j ^ (1 << i)], f[j]);
}

bool check(int j, int l) {

    for(int i = 0; i < l / 2; ++i)
        if(bool(j & (1 << i) == bool(j & (1 << (l - i - 1))))) return false;
    return true;

}

void solve(int n, int L, int mx)
{

    mask[0][0] = 0;
    for (int i = 1; i < mx; i++)
        for (int j = 0; j < (1 << i); j++)
            mask[i][j] = gen(i, j);
    int all = (1 << n) - 1;
    if (2 * L < mx)
    {
        int ans = 0;
        for (int j = 0; j < (1 << L); j++)
            if (mask[L][j] == all) ans++;
        printf("%d\n", ans);
        return;
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1;
    int sz0 = ac[0].sz;
    int sz1 = ac[1].sz;
    for (int i = 0; i < L; i++)
        for (int j = 0; j < sz0; j++)
            for (int k = 0; k < sz1; k++)
                for (int s = 0; s < (1 << n); s++)
                    if (dp[i][j][k][s])
                        for (int c = 0; c < 2; c++)
                        {
                            int x = ac[0].ch[j][c];
                            int y = ac[1].ch[k][c ^ 1];
                            int t = s | ac[0].val[x] | ac[1].val[y];
                            update(dp[i + 1][x][y][t], dp[i][j][k][s]);
                        }
    int ans = 0;
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i <= L; i++)
        for (int j = 0; j < sz0; j++)
            for (int k = 0; k < sz1; k++)
                for (int s = 0; s < (1 << n); s++)
                    update(tmp[i][s], dp[i][j][k][s]);
    for (int i = 0; i <= L; i++)
        fwt(tmp[i], 1 << n);
    for (int i = 0; i < mx; i++)
        for (int j = 0; j < (1 << i); j++)
            update(ans, tmp[L - i][all ^ mask[i][j]]);
    printf("%d\n", ans);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, L;
        scanf("%d%d", &n, &L);
        ac[0].init();
        ac[1].init();
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%s", s);
            ac[0].insert(s, i);
            int m = strlen(s);
            if (mx < m) mx = m;
            reverse(s, s + m);
            ac[1].insert(s, i);
        }
        ac[0].build();
        ac[1].build();
        solve(n, L, mx);
    }
}