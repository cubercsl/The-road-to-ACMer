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

namespace FFT
{
const double PI = acos(-1.0);
struct Complex
{
    double x, y;
    Complex(double x = 0.0, double y = 0.0) { this->x = x, this->y = y; }
    Complex operator-(const Complex& b) const { return Complex(x - b.x, y - b.y); }
    Complex operator+(const Complex& b) const { return Complex(x + b.x, y + b.y); }
    Complex operator*(const Complex& b) const { return Complex(x * b.x - y * b.y, x * b.y + y * b.x); }
};

void fft(vector<Complex>& y, int len, int on)
{
    for (int i = 1, j = len / 2; i < len - 1; i++)
    {
        if (i < j) swap(y[i], y[j]);
        int k = len / 2;
        while (j >= k) j -= k, k /= 2;
        if (j < k) j += k;
    }
    for (int h = 2; h <= len; h <<= 1)
    {
        Complex wn(cos(-on * 2 * PI / h), sin(-on * 2 * PI / h));
        for (int j = 0; j < len; j += h)
        {
            Complex w(1, 0);
            for (int k = j; k < j + h / 2; k++)
            {
                Complex u = y[k];
                Complex t = w * y[k + h / 2];
                y[k] = u + t, y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (on == -1)
        for (int i = 0; i < len; i++) y[i].x /= len;
}
template <class T>
vector<T> multiply(vector<T>& a, vector<T>& b)
{
    int n = a.size() + b.size() - 1;
    int len = 1;
    while (len < n) len <<= 1;
    vector<Complex> aa(len), bb(len);
    vector<T> ret(n);
    for (int i = 0; i < a.size(); i++) aa[i] = a[i];
    for (int i = 0; i < b.size(); i++) bb[i] = b[i];
    fft(aa, len, 1), fft(bb, len, 1);
    for (int i = 0; i < len; i++) aa[i] = aa[i] * bb[i];
    fft(aa, len, -1);
    for (int i = 0; i < n; i++) ret[i] = (T)(aa[i].x + 0.5);
    return ret;
}
}; // namespace FFT

const int N = 1 << 20;
int a[N], pre[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 1, s; i <= n; i++)
    {
        scanf("%d", &s);
        a[i] = s < x;
    }
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    vector<ll> aa(n + 1), bb(n + 1);
    for (int i = 0; i <= n; i++) aa[pre[i]]++;
    for (int i = 0; i <= n; i++) bb[n - pre[i]]++;
    auto ans = FFT::multiply(aa, bb);
    ans[n] -= (n + 1);
    ans[n] >>= 1;
    for (int i = n; i <= n * 2; i++) cout << ans[i] << " ";
    return 0;
}
