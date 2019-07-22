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
}; // namespace fft

int main()
{
    string s, t;
    cin >> s >> t;
    reverse(t.begin(), t.end());
    int n = s.length(), m = t.length();
    vector<int> a(s.length()), b(t.length());
    vector<int> ans(n - m + 1);
    for (int c = 0; c < 2; c++)
    {
        for (int i = 0; i < n; i++) a[i] = s[i] == (c + '0');
        for (int i = 0; i < m; i++) b[i] = t[i] != (c + '0');
        auto v = fft::multiply(a, b);
        for (int i = 0; i < n - m + 1; i++) ans[i] += v[m + i - 1];
    }
    int cnt = 0;
    for(auto& t : ans)
        if (t & 1 ^ 1) cnt++;
    printf("%d\n", cnt);
}