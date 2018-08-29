#include <bits/stdc++.h>
using namespace std;

namespace fft
{
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

int base = 1;
vector<cp> roots = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};

const db PI = acosl(-1.0);

void ensure_base(int nbase)
{
    if (nbase <= base) return;
    rev.resize(static_cast<unsigned long>(1 << nbase));
    for (int i = 0; i < (1 << nbase); i++)
        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    roots.resize(static_cast<unsigned long>(1 << nbase));
    while (base < nbase)
    {
        db angle = 2 * PI / (1 << (base + 1));
        for (int i = 1 << (base - 1); i < (1 << base); i++)
        {
            roots[i << 1] = roots[i];
            db angle_i = angle * (2 * i + 1 - (1 << base));
            roots[(i << 1) + 1] = cp(cos(angle_i), sin(angle_i));
        }
        base++;
    }
}

void fft(vector<cp>& a, int n = -1)
{
    if (n == -1) n = a.size();
    assert((n & (n - 1)) == 0);
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for (int i = 0; i < n; i++)
        if (i < (rev[i] >> shift))
            swap(a[i], a[rev[i] >> shift]);
    for (int k = 1; k < n; k <<= 1)
        for (int i = 0; i < n; i += 2 * k)
            for (int j = 0; j < k; j++)
            {
                cp z = a[i + j + k] * roots[j + k];
                a[i + j + k] = a[i + j] - z;
                a[i + j] = a[i + j] + z;
            }
}

vector<cp> fa, fb;

vector<int> multiply(vector<int>& a, vector<int>& b)
{
    int need = a.size() + b.size() - 1;
    int nbase = 0;
    while ((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    int sz = 1 << nbase;
    if (sz > (int)fa.size())
        fa.resize(static_cast<unsigned long>(sz));
    for (int i = 0; i < sz; i++)
    {
        int x = (i < (int)a.size() ? a[i] : 0);
        int y = (i < (int)b.size() ? b[i] : 0);
        fa[i] = cp(x, y);
    }
    fft(fa, sz);
    cp r(0, -0.25 / sz);
    for (int i = 0; i <= (sz >> 1); i++)
    {
        int j = (sz - i) & (sz - 1);
        cp z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
        if (i != j)
        {
            fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;
        }
        fa[i] = z;
    }
    fft(fa, sz);
    vector<int> res(static_cast<unsigned long>(need));
    for (int i = 0; i < need; i++)
    {
        res[i] = fa[i].x + 0.5;
    }
    return res;
}
}; // namespace fft

constexpr int N = 1 << 21;
bitset<N> s;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(m + 1);
    for (int i = 0, x; i < n; i++)
    {
        scanf("%d", &x);
        s.set(x);
        a[x] = 1;
    }
    auto res = fft::multiply(a, a);
    vector<int> ans;
    for (int i = 1; i <= m; i++)
    {
        if (res[i] == 0 && s[i])
            ans.push_back(i);
        else if (res[i] && !s[i])
            return puts("NO"), 0;
    }
    puts("YES");
    printf("%d\n", static_cast<int>(ans.size()));
    for (auto& t : ans) printf("%d ", t);
}