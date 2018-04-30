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

const double PI = acos(-1.0);
struct Complex
{
    double x, y;
    Complex(double x = 0.0, double y = 0.0) : x(x), y(y) {}
    Complex operator-(const Complex& b) const { return Complex(x - b.x, y - b.y); }
    Complex operator+(const Complex& b) const { return Complex(x + b.x, y + b.y); }
    Complex operator*(const Complex& b) const { return Complex(x * b.x - y * b.y, x * b.y + y * b.x); }
};

void change(Complex y[], int len)
{
    for (int i = 1, j = len / 2; i < len - 1; i++)
    {
        if (i < j) swap(y[i], y[j]);
        int k = len / 2;
        while (j >= k) j -= k, k /= 2;
        if (j < k) j += k;
    }
}

void fft(Complex y[], int len, int on)
{
    change(y, len);
    for (int h = 2; h <= len; h <<= 1)
    {
        Complex wn(cos(-on * 2 * PI / h), sin(-on * 2 * PI / h));
        for (int j = 0; j < len; j += h)
        {
            Complex w(1, 0);
            for (int k = j; k < j + h / 2; k++)
            {
                Complex u = y[k], t = w * y[k + h / 2];
                y[k] = u + t, y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (on == -1)
        for (int i = 0; i < len; i++) y[i].x /= len;
}

const int N = 1 << 20;
Complex x[N], y[N];
int G[N][6][6];
int fa[6];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    string s, t;
    cin >> s >> t;
    reverse(t.begin(), t.end());
    int a = s.length(), b = t.length();
    int n = 1;
    while (n < (a + b)) n <<= 1;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            if (i != j)
            {
                for (int k = 0; k < n; k++) x[k] = k < a ? Complex(s[k] == i + 'a') : 0;
                for (int k = 0; k < n; k++) y[k] = k < b ? Complex(t[k] == j + 'a') : 0;
                fft(x, n, 1), fft(y, n, 1);
                for (int k = 0; k < n; k++) x[k] = x[k] * y[k];
                fft(x, n, -1);
                for (int k = 0; k < a - b + 1; k++) G[k][i][j] = (int)(x[b + k - 1].x + 0.5);
            }
    for (int k = 0; k < a - b + 1; k++)
    {
        int ans = 0;
        iota(fa, fa + 6, 0);
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                if (G[k][i][j] || G[k][j][i])
                {
                    int u = find(i), v = find(j);
                    if (u == v) continue;
                    ans++;
                    fa[v] = u;
                }
        cout << ans << " ";
    }

    return 0;
}