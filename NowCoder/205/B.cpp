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

typedef long long ll;
typedef unsigned long long ull;

using i64 = long long;
using u64 = unsigned long long;
using u128 = __uint128_t;

struct Mod64
{
    Mod64() : n_(0) {}
    Mod64(u64 n) : n_(init(n)) {}
    static u64 modulus() { return mod; }
    static u64 init(u64 w) { return reduce(u128(w) * r2); }
    static void set_mod(u64 m)
    {
        mod = m;
        assert(mod & 1);
        inv = m;
        for (int i = 0; i < 5; ++i) inv *= 2 - inv * m;
        r2 = -u128(m) % m;
    }
    static u64 reduce(u128 x)
    {
        u64 y = u64(x >> 64) - u64((u128(u64(x) * inv) * mod) >> 64);
        return i64(y) < 0 ? y + mod : y;
    }
    Mod64& operator+=(Mod64 rhs)
    {
        n_ += rhs.n_ - mod;
        if (i64(n_) < 0) n_ += mod;
        return *this;
    }
    Mod64 operator+(Mod64 rhs) const { return Mod64(*this) += rhs; }
    Mod64& operator*=(Mod64 rhs)
    {
        n_ = reduce(u128(n_) * rhs.n_);
        return *this;
    }
    Mod64 operator*(Mod64 rhs) const { return Mod64(*this) *= rhs; }
    u64 get() const { return reduce(n_); }
    static u64 mod, inv, r2;
    u64 n_;
};
u64 Mod64::mod, Mod64::inv, Mod64::r2;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ull A0, A1, M0, M1, C, M;
        int k;
        scanf("%llu%llu%llu%llu%llu%llu%d", &A0, &A1, &M0, &M1, &C, &M, &k);
        Mod64::set_mod(M);
        Mod64 a0(A0), a1(A1), m0(M0), m1(M1), c(C), ans(1), a2(0);
        for (int i = 0; i <= k; i++)
        {
            ans = ans * a0;
            a2 = m0 * a1 + m1 * a0 + c;
            a0 = a1;
            a1 = a2;
        }
        printf("%llu\n", ans.get());
    }
}
