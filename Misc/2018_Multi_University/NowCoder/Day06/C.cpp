#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// #define ENABLE_FREAD

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

const int mod = 119 << 23 | 1;
const int maxn = 1 << 20;
const int p = mod;
ll Pow(ll a, ll n, ll p)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= p)
        if (n & 1) (t *= a) %= p;
    return t;
}
ll f[maxn];
ll inv[maxn];
void init()
{
    f[0] = 1;
    for (int i = 1; i < maxn; i++) f[i] = (f[i - 1] * i) % p;
    inv[maxn - 1] = Pow(f[maxn - 1], p - 2, p);
    for (int i = maxn - 2; ~i; i--) inv[i] = inv[i + 1] * (i + 1) % p;
}
ll C(int n, int m) { return f[n] * inv[m] % p * inv[n - m] % p; }

int main()
{
    init();
    int T = io.ri(), kase = 0;
    while (T--)
    {
        ll n, m;
        io >> n >> m;
        ll ans = 1;
        bool flag = n > m;
        ll t = min(n, m);
        ll tmp = (max(n, m) - 1) % p;
        for (int i = 1; i < t; i++)
        {
            if (flag)
            {
                ans += tmp * C(m - 1, i) % p;
                (tmp *= (n - i - 1) % p) %= p;
            }
            else
            {
                ans += tmp * C(n - 1, i) % p;
                (tmp *= (m - i - 1) % p) %= p;
            }
            ans %= p;
        }
        (ans *= (m % p)) %= p;
        io << "Case #" << ++kase << ": " << ans << nl;
    }

    return 0;
}
} // namespace solution

int main()
{
    return solution::main();
}