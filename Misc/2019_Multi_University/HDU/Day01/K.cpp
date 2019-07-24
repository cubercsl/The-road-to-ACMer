#include <bits/stdc++.h>
using namespace std;

namespace fft
{

typedef int type;

typedef double db;

struct cp
{
    db x, y;

    cp() { x = y = 0; }

    cp(db x, db y) : x(x), y(y) {}
};

inline cp operator+(cp a, cp b) { return cp(a.x + b.x, a.y + b.y); }

inline cp operator-(cp a, cp b) { return cp(a.x - b.x, a.y - b.y); }

inline cp operator*(cp a, cp b) { return cp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }

inline cp conj(cp a) { return cp(a.x, -a.y); }

type base = 1;
vector<cp> roots = {{0, 0},
                    {1, 0}};
vector<type> rev = {0, 1};

const db PI = acosl(-1.0);

void ensure_base(type nbase)
{
    if (nbase <= base)
    {
        return;
    }
    rev.resize(static_cast<unsigned long>(1 << nbase));
    for (type i = 0; i < (1 << nbase); i++)
    {
        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    roots.resize(static_cast<unsigned long>(1 << nbase));
    while (base < nbase)
    {
        db angle = 2 * PI / (1 << (base + 1));
        for (type i = 1 << (base - 1); i < (1 << base); i++)
        {
            roots[i << 1] = roots[i];
            db angle_i = angle * (2 * i + 1 - (1 << base));
            roots[(i << 1) + 1] = cp(cos(angle_i), sin(angle_i));
        }
        base++;
    }
}

void fft(vector<cp>& a, type n = -1)
{
    if (n == -1)
    {
        n = a.size();
    }
    assert((n & (n - 1)) == 0);
    type zeros = __builtin_ctz(n);
    ensure_base(zeros);
    type shift = base - zeros;
    for (type i = 0; i < n; i++)
    {
        if (i < (rev[i] >> shift))
        {
            swap(a[i], a[rev[i] >> shift]);
        }
    }
    for (type k = 1; k < n; k <<= 1)
    {
        for (type i = 0; i < n; i += 2 * k)
        {
            for (type j = 0; j < k; j++)
            {
                cp z = a[i + j + k] * roots[j + k];
                a[i + j + k] = a[i + j] - z;
                a[i + j] = a[i + j] + z;
            }
        }
    }
}

vector<cp> fa, fb;

vector<type> multiply(vector<type>& a, vector<type>& b)
{
    type need = a.size() + b.size() - 1;
    type nbase = 0;
    while ((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    type sz = 1 << nbase;
    if (sz > (type)fa.size())
        fa.resize(static_cast<unsigned long>(sz));
    for (type i = 0; i < sz; i++)
    {
        type x = (i < (type)a.size() ? a[i] : 0);
        type y = (i < (type)b.size() ? b[i] : 0);
        fa[i] = cp(x, y);
    }
    fft(fa, sz);
    cp r(0, -0.25 / sz);
    for (type i = 0; i <= (sz >> 1); i++)
    {
        type j = (sz - i) & (sz - 1);
        cp z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
        if (i != j)
        {
            fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;
        }
        fa[i] = z;
    }
    fft(fa, sz);
    vector<type> res(static_cast<unsigned long>(need));
    for (type i = 0; i < need; i++)
    {
        res[i] = fa[i].x + 0.5;
    }
    return res;
}

vector<type> multiply_mod(vector<type>& a, vector<type>& b, type m, type eq = 0)
{
    type need = a.size() + b.size() - 1;
    type nbase = 0;
    while ((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    type sz = 1 << nbase;
    if (sz > (type)fa.size())
    {
        fa.resize(static_cast<unsigned long>(sz));
    }
    for (type i = 0; i < (type)a.size(); i++)
    {
        type x = (a[i] % m + m) % m;
        fa[i] = cp(x & ((1 << 15) - 1), x >> 15);
    }
    fill(fa.begin() + a.size(), fa.begin() + sz, cp{0, 0});
    fft(fa, sz);
    if (sz > (type)fb.size())
    {
        fb.resize(static_cast<unsigned long>(sz));
    }
    if (eq)
    {
        copy(fa.begin(), fa.begin() + sz, fb.begin());
    }
    else
    {
        for (type i = 0; i < (type)b.size(); i++)
        {
            type x = (b[i] % m + m) % m;
            fb[i] = cp(x & ((1 << 15) - 1), x >> 15);
        }
        fill(fb.begin() + b.size(), fb.begin() + sz, cp{0, 0});
        fft(fb, sz);
    }
    db ratio = 0.25 / sz;
    cp r2(0, -1);
    cp r3(ratio, 0);
    cp r4(0, -ratio);
    cp r5(0, 1);
    for (type i = 0; i <= (sz >> 1); i++)
    {
        type j = (sz - i) & (sz - 1);
        cp a1 = (fa[i] + conj(fa[j]));
        cp a2 = (fa[i] - conj(fa[j])) * r2;
        cp b1 = (fb[i] + conj(fb[j])) * r3;
        cp b2 = (fb[i] - conj(fb[j])) * r4;
        if (i != j)
        {
            cp c1 = (fa[j] + conj(fa[i]));
            cp c2 = (fa[j] - conj(fa[i])) * r2;
            cp d1 = (fb[j] + conj(fb[i])) * r3;
            cp d2 = (fb[j] - conj(fb[i])) * r4;
            fa[i] = c1 * d1 + c2 * d2 * r5;
            fb[i] = c1 * d2 + c2 * d1;
        }
        fa[j] = a1 * b1 + a2 * b2 * r5;
        fb[j] = a1 * b2 + a2 * b1;
    }
    fft(fa, sz);
    fft(fb, sz);
    vector<type> res(static_cast<unsigned long>(need));
    for (type i = 0; i < need; i++)
    {
        long long aa = fa[i].x + 0.5;
        long long bb = fb[i].x + 0.5;
        long long cc = fa[i].y + 0.5;
        res[i] = (aa + ((bb % m) << 15) + ((cc % m) << 30)) % m;
    }
    return res;
}

vector<type> square(vector<type>& a)
{
    return multiply(a, a);
}

vector<type> square_mod(vector<type>& a, type m)
{
    return multiply_mod(a, a, m, 1);
}

vector<type> kiss_me(vector<type>& b, long long k, type mod)
{
    vector<type> a = b;
    vector<type> res(1, 1);
    for (; k; k >>= 1, a = square_mod(a, mod))
    {
        if (k & 1)
        {
            res = multiply_mod(res, a, mod);
        }
    }
    return res;
}

pair<vector<type>, vector<type> > mul2(vector<type>& b, long long k)
{
    return make_pair(kiss_me(b, k, (type)1e9 + 7), kiss_me(b, k, (type)1e9 + 9));
}

vector<vector<type> > muln(vector<type>& b, long long k, vector<int> mod_list)
{
    vector<vector<type> > res(mod_list.size());
    for (int i = 0; i < mod_list.size(); ++i)
    {
        res[i] = kiss_me(b, k, mod_list[i]);
    }
    return res;
}

}; // namespace fft

typedef long long ll;
const int maxn = 1 << 21;
const int mod = 119 << 23 | 1;
ll Pow(ll a, ll n, ll mod)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

ll f[maxn];
ll inv[maxn];
void init()
{
    f[0] = 1;
    for (int i = 1; i < maxn; i++) f[i] = (f[i - 1] * i) % mod;
    inv[maxn - 1] = Pow(f[maxn - 1], mod - 2, mod);
    for (int i = maxn - 2; ~i; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}
ll C(int n, int m) { return f[n] * inv[m] % mod * inv[n - m] % mod; }
int main()
{
    init();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> a(n);
        int cnt[] = {0, 0, 0, 0};
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0, x; i < m; i++) scanf("%d", &x), cnt[x]++;
        for (int c = 1; c < 4; c++)
        {
            if (!cnt[c]) continue;
            vector<int> h(n);
            for (int i = 0; i * c < n; i++)
                h[i * c] = C(cnt[c] - 1 + i, i);
            a = fft::multiply_mod(h, a, mod);
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) ans ^= 1LL * (i + 1) * a[i];
        printf("%lld\n", ans);
    }
}