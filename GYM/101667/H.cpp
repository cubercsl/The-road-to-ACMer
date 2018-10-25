#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

struct Complex
{
    double x, y;
    Complex(double x = 0.0, double y = 0.0) : x(x), y(y) {}
    Complex operator-(const Complex& b) const { return Complex(x - b.x, y - b.y); }
    Complex operator+(const Complex& b) const { return Complex(x + b.x, y + b.y); }
    Complex operator*(const Complex& b) const { return Complex(x * b.x - y * b.y, x * b.y + y * b.x); }
};

void fft(Complex y[], int len, int on)
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

const int N = 1 << 18;
Complex a[N], b[N];
int ans[N];
char s[N], t[N];

char aa[] = "SPR";
char bb[] = "RSP";

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s%s", s, t);
    reverse(t, t + m);
    for (int tt = 0; tt < 3; tt++)
    {
        for (int i = 0; i < N; i++)
            a[i] = Complex(s[i] == aa[tt], 0);
        for (int i = 0; i < N; i++)
            b[i] = Complex(t[i] == bb[tt], 0);

        fft(a, N, 1);
        fft(b, N, 1);
        for (int i = 0; i < N; i++) a[i] = a[i] * b[i];
        fft(a, N, -1);
    

        for (int i = 0; i < n; i++)
            ans[i] += static_cast<int>(a[m + i - 1].x + 0.5);
    }
    int ret = 0;
    for (int i = 0; i < n; i++) ret = max(ret, ans[i]);
    printf("%d\n", ret);
}