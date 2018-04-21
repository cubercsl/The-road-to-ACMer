#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

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
}

const int N = 1 << 17;
struct Base
{
    int a[31];
    Base() { clr(a, 0); }
    void insert(int x)
    {
        for (int i = 30; ~i; i--)
            if (x >> i & 1)
            {
                if (!a[i]) a[i] = x;
                x ^= a[i];
                if (!x) return;
            }
    }
    int query()
    {
        int x = 0;
        for (int i = 30; ~i; i--)
            if ((x ^ a[i]) > x) x ^= a[i];
        return x;
    }
    void operator+=(const Base& rhs)
    {
        for (int i = 0; i <= 30; i++) insert(rhs.a[i]);
    }
} dp[N], pre[N], suf[N];

vector<int> G[N];
int L[N], R[N], pos[N], dfn;
int a[N];

void dfs(int u, int fa)
{
    pos[++dfn] = u;
    L[u] = dfn;
    dp[u].insert(a[u]);
    for (auto& v : G[u])
    {
        if (v == fa) continue;
        dfs(v, u);
        dp[u] += dp[v];
    }
    R[u] = dfn;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    io::in(n);
    for (int i = 1; i <= n; i++) io::in(a[i]);
    for (int i = 1; i < n; i++)
    {
        static int u, v;
        io::in(u), io::in(v);
        G[u].pb(v), G[v].pb(u);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1], pre[i].insert(a[pos[i]]);
    for (int i = n; i >= 1; i--) suf[i] = suf[i + 1], suf[i].insert(a[pos[i]]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        Base tmp = pre[L[i] - 1];
        tmp += suf[R[i] + 1];
        ans = max(ans, dp[i].query() + tmp.query());
    }
    io::out_int(ans);
    io::write();
    return 0;
}