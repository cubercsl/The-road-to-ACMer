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

const int maxn = 1 << 20;

struct Complex
{
    double x, y;
    Complex(double _x = 0.0, double _y = 0.0)
    {
        x = _x;
        y = _y;
    }
    Complex operator-(const Complex& b) const
    {
        return Complex(x - b.x, y - b.y);
    }
    Complex operator+(const Complex& b) const
    {
        return Complex(x + b.x, y + b.y);
    }
    Complex operator*(const Complex& b) const
    {
        return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
    }
};

void change(Complex y[], int len)
{
    for (int i = 1, j = len / 2; i < len - 1; i++)
    {
        if (i < j)
            swap(y[i], y[j]);
        int k = len / 2;
        while (j >= k)
        {
            j -= k;
            k /= 2;
        }
        if (j < k)
            j += k;
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
                Complex u = y[k];
                Complex t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (on == -1)
        for (int i = 0; i < len; i++)
            y[i].x /= len;
}

char S[maxn], T[maxn];
Complex s[maxn], t[maxn];
int bitmask[maxn];
int sum[maxn];
int cnt[4];
map<char, int> M;

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    M['A'] = 0, M['G'] = 1, M['C'] = 2, M['T'] = 3;
    int n, m, k;
    while (~scanf("%d%d%d", &n, &m, &k))
    {
        scanf("%s%s", S, T);
        reverse(T, T + m);
        clr(cnt, 0);
        clr(sum, 0);
        clr(bitmask, 0);
        int L = 0, R = min(n, k) - 1;
        for (int i = L; i <= R; i++) cnt[M[S[i]]]++;
        for (int i = 0; i < n; i++)
        {
            if (R + 1 < n) cnt[M[S[++R]]]++;
            if (i - L > k) cnt[M[S[L++]]]--;
            for (int j = 0; j < 4; j++)
                if (cnt[j]) bitmask[i] |= (1 << j);
        }
        int N = 1;
        while (N < (n + m)) N <<= 1;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < n; j++)
                s[j] = ((bitmask[j] >> i) & 1) ? Complex(1, 0) : Complex(0, 0);
            for (int j = n; j < N; j++)
                s[j] = Complex(0, 0);

            for (int j = 0; j < m; j++)
                t[j] = M[T[j]] == i ? Complex(1, 0) : Complex(0, 0);
            for (int j = m; j < N; j++)
                t[j] = Complex(0, 0);

            fft(s, N, 1);
            fft(t, N, 1);
            for (int j = 0; j < N; j++)
                s[j] = s[j] * t[j];
            fft(s, N, -1);
            for (int j = m - 1; j < n; j++)
                sum[j] += (int)(s[j].x + 0.5);
        }
        int ans = 0;
        for (int i = m - 1; i < n; i++)
            if (sum[i] == m) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
