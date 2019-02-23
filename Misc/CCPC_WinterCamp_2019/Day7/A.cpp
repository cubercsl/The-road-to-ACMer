#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize(3)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target("sse3", "sse2", "sse")
#pragma GCC target("avx", "sse4", "sse4.1", "sse4.2", "ssse3")
#pragma GCC target("f16c")
#pragma GCC optimize("inline", "fast-math", "unroll-loops", "no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#pragma GCC diagnostic error "-std=c++14"
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define ENABLE_FREAD

namespace io_impl
{
inline bool maybe_digit(char c)
{
    return c >= '0' && c <= '9';
}

inline bool maybe_decimal(char c)
{
    return (c >= '0' && c <= '9') || (c == '.');
}

struct io_s
{

    bool negative;
    bool ok = true;
    char ch = next_char();

    int precious = 6;
    long double epslion = 1e-6;

#ifdef ENABLE_FREAD
    inline char next_char()
    {
        static char buf[100000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
    }
#else
    inline char next_char() const
    {
        return getchar();
    }
#endif

    /// read int

    template <typename T>
    inline bool rn(T& _v)
    {
        negative = false;
        _v = 0;
        while (!maybe_digit(ch) && ch != EOF)
        {
            negative = ch == '-';
            ch = next_char();
        };
        if (ch == EOF) return ok = false;
        do
        {
            _v = (_v << 1) + (_v << 3) + ch - '0';
        } while (maybe_digit(ch = next_char()));
        if (negative) _v = -_v;
        return true;
    }

    template <typename T>
    inline void rn_unsafe(T& _v)
    {
        negative = false;
        _v = 0;
        while (!maybe_digit(ch))
        {
            negative = ch == '-';
            ch = next_char();
        };
        do
        {
            _v = (_v << 1) + (_v << 3) + ch - '0';
        } while (maybe_digit(ch = next_char()));
        if (negative) _v = -_v;
    }

    template <typename T>
    inline T rn()
    {
        T v = T();
        rn_unsafe(v);
        return v;
    }

    inline int ri() { return rn<int>(); }
    inline ll rll() { return rn<ll>(); }

    /// read unsigned

    template <typename T>
    inline bool run(T& _v)
    {
        _v = 0;
        while (!maybe_digit(ch) && ch != EOF) ch = next_char();
        if (ch == EOF) return ok = false;
        do
        {
            _v = (_v << 1) + (_v << 3) + ch - '0';
        } while (maybe_digit(ch = next_char()));
        return true;
    }

    template <typename T>
    inline void run_unsafe(T& _v)
    {
        _v = 0;
        while (!maybe_digit(ch)) ch = next_char();
        do
        {
            _v = (_v << 1) + (_v << 3) + ch - '0';
        } while (maybe_digit(ch = next_char()));
    }

    template <typename T>
    inline T run()
    {
        T v = T();
        run_unsafe(v);
        return v;
    }

    /// read double

    template <typename T>
    inline bool rd(T& _v)
    {
        negative = false;
        _v = 0;
        while (!maybe_digit(ch) && ch != EOF)
        {
            negative = ch == '-';
            ch = next_char();
        };
        if (ch == EOF) return ok = false;
        do
        {
            _v = (_v * 10) + (ch - '0');
        } while (maybe_digit(ch = next_char()));
        static int stk[70], tp;
        if (ch == '.')
        {
            tp = 0;
            T _v2 = 0;
            while (maybe_digit(ch = next_char()))
            {
                stk[tp++] = ch - '0';
            }
            while (tp--)
            {
                _v2 = _v2 / 10 + stk[tp];
            }
            _v += _v2 / 10;
        }
        if (ch == 'e' || ch == 'E')
        {
            ch = next_char();
            static bool _neg = false;
            if (ch == '+')
                ch = next_char();
            else if (ch == '-')
                _neg = true, ch = next_char();
            if (maybe_digit(ch))
            {
                _v *= pow(10, run<ll>() * (_neg ? -1 : 1));
            }
        }
        if (negative) _v = -_v;
        return true;
    }

    template <typename T>
    inline T rd()
    {
        T v = T();
        rd(v);
        return v;
    }

    /// read string

    inline int gets(char* s)
    {
        char* c = s;
        while (ch == '\n' || ch == '\r' || ch == ' ') ch = next_char();
        if (ch == EOF) return (ok = false), *c = 0;
        do
        {
            *(c++) = ch;
            ch = next_char();
        } while (ch != '\n' && ch != '\r' && ch != ' ' && ch != EOF);
        *(c++) = '\0';
        return static_cast<int>(c - s - 1);
    }

    inline int getline(char* s)
    {
        char* c = s;
        while (ch == '\n' || ch == '\r') ch = next_char();
        if (ch == EOF) return (ok = false), *c = 0;
        do
        {
            *(c++) = ch;
            ch = next_char();
        } while (ch != '\n' && ch != '\r' && ch != EOF);
        *(c++) = '\0';
        return static_cast<int>(c - s - 1);
    }

    inline char get_alpha()
    {
        while (!isalpha(ch)) ch = next_char();
        const char ret = ch;
        ch = next_char();
        return ret;
    }

    inline char get_nonblank()
    {
        while (isblank(ch)) ch = next_char();
        const char ret = ch;
        ch = next_char();
        return ret;
    }

    inline char get_char()
    {
        const char ret = ch;
        ch = next_char();
        return ret;
    }

    template <typename T>
    inline void o(T p)
    {
        static int stk[70], tp;
        if (p == 0)
        {
            putchar('0');
            return;
        }
        if (p < 0)
        {
            p = -p;
            putchar('-');
        }
        while (p) stk[++tp] = p % 10, p /= 10;
        while (tp) putchar(stk[tp--] + '0');
    }

    template <typename T>
    inline void od(T v)
    {
        static int stk[70], tp;
        tp = 0;
        if (fabs(v) < epslion / 10)
        {
            putchar('0');
            if (precious > 0)
            {
                putchar('.');
                for (int i = 0; i < precious; ++i) putchar('0');
            }
            return;
        }
        else
        {
            if (v < 0)
            {
                v = -v;
                putchar('-');
            }
            v += epslion / 2;
            T p = floor(v) + epslion / 10;
            while (fabs(p) > 1 - epslion)
            {
                stk[++tp] = fmod(p, 10), p /= 10;
            }
            while (tp) putchar(stk[tp--] + '0');
        }
        if (precious == 0) return;
        putchar('.');
        v -= floor(v);
        for (int i = 0; i < precious; ++i)
        {
            v *= 10;
            putchar((int)floor(v) + '0');
            v = fmod(v, 1);
        }
    }

    /// Enhancement

    typedef void io_operator(io_s& v);
    typedef char* charptr;

    template <typename T>
    inline io_s& operator>>(T& x)
    {
        if (numeric_limits<T>::is_signed)
            rn(x);
        else
            run(x);
        return *this;
    }

    template <typename T>
    inline io_s& operator<<(const T& x);

    inline io_s& operator<<(io_operator* v)
    {
        v(*this);
        return *this;
    }

    operator bool() const { return ok; }

    void set_precious(int x)
    {
        precious = x;
        epslion = pow(10, -x);
    }
};

template <>
inline io_s& io_s::operator>>(char*& x)
{
    gets(x);
    return *this;
}

template <>
inline io_s& io_s::operator>>(float& x)
{
    rd(x);
    return *this;
}

template <>
inline io_s& io_s::operator>>(double& x)
{
    rd(x);
    return *this;
}

template <>
inline io_s& io_s::operator>>(long double& x)
{
    rd(x);
    return *this;
}

template <>
inline void io_s::o(const char* p)
{
    printf(p);
}

template <>
inline void io_s::o(const char p)
{
    putchar(p);
}

template <>
inline void io_s::o(float p)
{
    od(p);
}

template <>
inline void io_s::o(double p)
{
    od(p);
}

template <>
inline void io_s::o(long double p)
{
    od(p);
}

template <typename T>
inline io_s& io_s::operator<<(const T& x)
{
    o(x);
    return *this;
}

inline void new_line(io_s& v)
{
    v.o('\n');
}

io_s::io_operator* nl = new_line;
} // namespace io_impl

using namespace io_impl;

io_s io;

namespace solution
{
    #include <bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define lson_len (len - (len >> 1))
#define rson_len (len >> 1)
#define pb(x) push_back(x)
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define my_unique(a) a.resize(distance(a.begin(), unique(a.begin(), a.end())))
#define my_sort_unique(c) (sort(c.begin(), c.end())), my_unique(c)
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const int maxn = 3e6 + 6;
vector<int> G[maxn];
pii dp[maxn]; // <distance, id>
int seg[maxn << 2], lazy[maxn << 2], ans[maxn];
int n;

inline void pushup(int rt) { seg[rt] = min(seg[lson], seg[rson]); }
inline void pushdown(int rt)
{
    if (lazy[rt] == 0) return;
    lazy[lson] += lazy[rt];
    lazy[rson] += lazy[rt];
    seg[lson] += lazy[rt];
    seg[rson] += lazy[rt];
    lazy[rt] = 0;
}
void build(int l, int r, int rt)
{
    if (l == r)
    {
        seg[rt] = INF;
        return;
    }
    int m = l + r >> 1;
    build(l, m, lson);
    build(m + 1, r, rson);
    pushup(rt);
}
void SetPoint(int l, int r, int rt, int p, int x)
{
    if (l == r)
    {
        seg[rt] = x;
        return;
    }
    pushdown(rt);
    int m = l + r >> 1;
    if (m >= p)
        SetPoint(l, m, lson, p, x);
    else
        SetPoint(m + 1, r, rson, p, x);
    pushup(rt);
}
void update(int l, int r, int rt, int L, int R, int x)
{
    if (L > R) return;
    if (L <= l && r <= R)
    {
        seg[rt] += x;
        lazy[rt] += x;
        return;
    }
    pushdown(rt);
    int m = l + r >> 1;
    if (m >= L) update(l, m, lson, L, R, x);
    if (m < R) update(m + 1, r, rson, L, R, x);
    pushup(rt);
}
int query(int l, int r, int rt, int L, int R)
{
    if (L > R) return INF;
    if (L <= l && r <= R) return seg[rt];
    pushdown(rt);
    int m = l + r >> 1, ret = INF;
    if (m >= L) ret = min(ret, query(l, m, lson, L, R));
    if (m < R) ret = min(ret, query(m + 1, r, rson, L, R));
    return ret;
}
void dfs0(int u)
{
    if (G[u].size() == 0)
    {
        dp[u] = {0, u};
        return;
    }
    dp[u] = {INF, 0};
    for (auto& v : G[u])
    {
        dfs0(v);
        if (dp[u].first > dp[v].first)
            dp[u] = dp[v];
        else if (dp[u].first == dp[v].first && dp[u].second < dp[v].second)
            dp[u] = dp[v];
    }
    dp[u].first++;
}
void dfs1(int u)
{
    if (G[u].size() == 0)
    {
        ans[u] = query(1, n, 1, 1, dp[u].second - 1);
        return;
    }
    for (auto& v : G[u])
    {
        if (dp[u].second == dp[v].second)
        {
            update(1, n, 1, 1, dp[v].second - 1, 1);
            update(1, n, 1, dp[v].second, dp[v].second, -1);
            dfs1(v);
            update(1, n, 1, 1, dp[v].second - 1, -1);
            update(1, n, 1, dp[v].second, dp[v].second, 1);
        }
        else
        {
            update(1, n, 1, 1, dp[v].second - 1, 1);
            SetPoint(1, n, 1, dp[v].second, dp[v].first);
            dfs1(v);
            update(1, n, 1, 1, dp[v].second - 1, -1);
            SetPoint(1, n, 1, dp[v].second, INF);
        }
    }
}
int main()
{
    //	/*
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    //	*/
    scanf("%d", &n);
    for (int i = 1, u; i < n; i++)
    {
        scanf("%d", &u);
        G[u].push_back(i + 1);
    }
    build(1, n, 1);
    dfs0(1);
    SetPoint(1, n, 1, dp[1].second, dp[1].first);
    dfs1(1);
    for (int i = 1; i <= n; i++)
    {
        if (G[i].size() == 0)
        {
            if (ans[i] >= INF) ans[i] = -1;
            printf("%d %d\n", i, ans[i]);
        }
    }
}
} // namespace solution

int main()
{
    return solution::main();
}

