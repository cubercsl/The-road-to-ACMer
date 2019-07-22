#include <bits/stdc++.h>
using namespace std;
namespace io
{
const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf + 1;
inline void rnext()
{
    if (++ps == pe)
        pe = (ps = buf) + fread(buf, sizeof(char), sizeof(buf) / sizeof(char), stdin);
}

template <class T>
inline bool in(T& ans)
{
    ans = 0;
    T f = 1;
    if (ps == pe) return false; //EOF
    do
    {
        rnext();
        if ('-' == *ps) f = -1;
    } while (!isdigit(*ps) && ps != pe);
    if (ps == pe) return false; //EOF
    do
    {
        ans = (ans << 1) + (ans << 3) + *ps - 48;
        rnext();
    } while (isdigit(*ps) && ps != pe);
    ans *= f;
    return true;
}

const int MAXOUT = 10000;
char bufout[MAXOUT], outtmp[50], *pout = bufout, *pend = bufout + MAXOUT;
inline void write()
{
    fwrite(bufout, sizeof(char), pout - bufout, stdout);
    pout = bufout;
}
inline void out_char(char c)
{
    *(pout++) = c;
    if (pout == pend) write();
}
inline void out_str(char* s)
{
    while (*s)
    {
        *(pout++) = *(s++);
        if (pout == pend) write();
    }
}
template <class T>
inline void out_int(T x)
{
    if (!x)
    {
        out_char('0');
        return;
    }
    if (x < 0) x = -x, out_char('-');
    int len = 0;
    while (x)
    {
        outtmp[len++] = x % 10 + 48;
        x /= 10;
    }
    outtmp[len] = 0;
    for (int i = 0, j = len - 1; i < j; i++, j--) swap(outtmp[i], outtmp[j]);
    out_str(outtmp);
}
} // namespace io

const int maxn = 1e5 + 5;
vector<int> G[maxn];
bool vis[maxn];
int ans;
void dfs(int u, int fa)
{
    for (auto& v : G[u])
    {
        if (v == fa) continue;
        dfs(v, u);
        if (!vis[v] && !vis[u])
        {
            vis[v] = vis[u] = 1;
            ans += 2;
        }
    }
}
int main()
{
    int T;
    io::in(T);
    while (T--)
    {
        int n, k;
        io::in(n), io::in(k);
        for (int i = 1; i <= n; i++) G[i].clear();
        for (int i = 1, u; i < n; i++)
        {
            io::in(u);
            G[u].push_back(i + 1);
            G[i + 1].push_back(u);
            vis[i] = 0;
        }
        vis[n] = 0;
        ans = 0;
        dfs(1, 0);
        if (ans >= k)
            io::out_int((k + 1) / 2);
        else
            io::out_int(k - ans / 2);
        io::out_char('\n');
    }
    io::write();
    return 0;
}