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
const int mod = 119 << 23 | 1;
const double eps = 1e-6;

const int N = 1 << 20;
const int G = 3;
int wn[20];

int Pow(int a, int n, int mod)
{
    int t = 1;
    for (; n; n >>= 1, a = 1LL * a * a % mod)
        if (n & 1) t = 1LL * t * a % mod;
    return t;
}

void getwn()
{
    for (int i = 0; i < 20; i++) wn[i] = Pow(G, (mod - 1) / (1 << i), mod);
}
void change(VI& y, int len)
{
    for (int i = 1, j = len / 2; i < len - 1; i++)
    {
        if (i < j) swap(y[i], y[j]);
        int k = len / 2;
        while (j >= k) j -= k, k /= 2;
        if (j < k) j += k;
    }
}
void ntt(VI& y, int len, int on)
{
    change(y, len);
    for (int h = 2, id = 1; h <= len; h <<= 1, id++)
    {
        for (int j = 0; j < len; j += h)
        {
            int w = 1;
            for (int k = j; k < j + h / 2; k++)
            {
                int u = y[k] % mod;
                int t = 1LL * w * (y[k + h / 2] % mod) % mod;
                y[k] = (u + t) % mod, y[k + h / 2] = ((u - t) % mod + mod) % mod;
                w = 1LL * w * wn[id] % mod;
            }
        }
    }
    if (on == -1)
    {
        int inv = Pow(len, mod - 2, mod);
        for (int i = 1; i < len / 2; i++) swap(y[i], y[len - i]);
        for (int i = 0; i < len; i++) y[i] = 1LL * y[i] * inv % mod;
    }
}

VI operator*(VI a, VI b)
{
    int m = a.size() + b.size() - 1;
    int len = 1;
    while (len < m) len <<= 1;
    VI c(len);
    a.resize(len), b.resize(len);
    ntt(a, len, 1), ntt(b, len, 1);
    for (int i = 0; i < len; i++) c[i] = 1LL * a[i] * b[i] % mod;
    ntt(c, len, -1);
    c.resize(m);
    return c;
}

VI gao(int l, int r, const vector<VI>& v)
{
    if (l + 1 == r) return v[l];
    int m = l + r >> 1;
    return gao(l, m, v) * gao(m, r, v);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    getwn();
    int n;
    scanf("%d", &n);
    vector<VI> v(n, VI(2));
    for (auto& t : v) scanf("%d", &t[0]), t[1] = 1;
    VI ans = gao(0, n, v);
    for (auto& t : ans) printf("%d ", t);
    return 0;
}
