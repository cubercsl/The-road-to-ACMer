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

inline void Mod(int& a)
{
    if (a >= mod) a -= mod;
    if (a < 0) a += mod;
}

const int N = 16;
struct poly
{
    int c[N];
    poly() { memset(c, 0, sizeof(c)); }
    poly& operator=(const poly& b) { memcpy(c, b.c, sizeof(c)); }
    poly operator+(const poly& b)
    {
        poly ret;
        for (int i = 0; i < N; i++) Mod(ret.c[i] = c[i] + b.c[i]);
        return ret;
    }
    poly operator-(const poly& b)
    {
        poly ret;
        for (int i = 0; i < N; i++) Mod(ret.c[i] = c[i] - b.c[i]);
        return ret;
    }
    poly operator*(const poly& b)
    {
        poly ret;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N - i; j++)
                Mod(ret.c[i + j] += 1LL * c[i] * b.c[j] % mod);
        return ret;
    }
};

template <class T>
void fmt(vector<T>& a)
{
    int n = a.size();
    int m = __builtin_ctz(n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (!(j >> i & 1)) a[j | (1 << i)] = a[j | (1 << i)] + a[j];
}

template <class T>
void ifmt(vector<T>& a)
{
    int n = a.size();
    int m = __builtin_ctz(n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (!(j >> i & 1)) a[j | (1 << i)] = a[j | (1 << i)] - a[j];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int N;
    while (~scanf("%d", &N))
    {
        int n = 1;
        while (n < N) n <<= 1;
        vector<poly> a(n), b(n);
        for (int i = 0; i < N; i++) scanf("%d", &a[i].c[__builtin_popcount(i)]);
        for (int i = 0; i < N; i++) scanf("%d", &b[i].c[__builtin_popcount(i)]);
        fmt(a), fmt(b);
        for (int i = 0; i < n; i++) a[i] = a[i] * b[i];
        ifmt(a);
        for (int i = 0; i < N; i++) printf("%d%c", a[i].c[__builtin_popcount(i)], i == N - 1 ? '\n' : ' ');
    }
    return 0;
}