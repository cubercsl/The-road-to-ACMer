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

char S[100010];
char T[100010];
const int maxn = 1 << 19;
Complex s[maxn], t[maxn];
int sum[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (~scanf("%s%s", S, T))
    {
        int a = strlen(S);
        int b = strlen(T);
        reverse(T, T + b);
        int n = 1;
        while (n <= (a + b)) n <<= 1;
        for (int i = 0; i < n; i++)
        {
            if (i < a && S[i] == 'b')
                s[i] = Complex(1, 0);
            else
                s[i] = Complex(0, 0);
            if (i < b && T[i] == 'a')
                t[i] = Complex(1, 0);
            else
                t[i] = Complex(0, 0);
        }
        fft(s, n, 1);
        fft(t, n, 1);
        for (int i = 0; i < n; i++)
            s[i] = s[i] * t[i];
        fft(s, n, -1);
        for (int i = 0; i < a - b + 1; i++)
            sum[i] = (int)(s[b + i - 1].x + 0.5);
        // for (int i = 0; i < a - b + 1; i++)
        // printf("%d%c", sum[i], ' ');
        // puts("");
        for (int i = 0; i < n; i++)
        {
            if (i < a && S[i] == 'a')
                s[i] = Complex(1, 0);
            else
                s[i] = Complex(0, 0);
            if (i < b && T[i] == 'b')
                t[i] = Complex(1, 0);
            else
                t[i] = Complex(0, 0);
        }
        fft(s, n, 1);
        fft(t, n, 1);
        for (int i = 0; i < n; i++)
            s[i] = s[i] * t[i];
        fft(s, n, -1);
        int ans = INF;
        for (int i = 0; i < a - b + 1; i++)
        {
            sum[i] += (int)(s[b + i - 1].x + 0.5);
            // printf("%d ", (int)(s[b + i - 1].x + 0.5));
            ans = min(ans, sum[i]);
        }
        // puts("");
        printf("%d\n", ans);
        // puts("");
    }
    return 0;
}
