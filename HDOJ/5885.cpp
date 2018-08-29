#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

struct Complex
{
    double x, y;
    Complex(double _x = 0.0, double _y = 0.0) { x = _x, y = _y; }
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

const int N = 1 << 20;
Complex a[N], b[N];

int main()
{
    int n, m;
    double r;
    while (~scanf("%d%d%lf", &n, &m, &r))
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int R = ceil(r);
        int M = m + 2 * R;
        int len = 1;
        while (len <= M * M) len <<= 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%lf", &a[i * M + j].x), a[i * M + j].y = 0;
        for (int i = -R; i <= R; i++)
            for (int j = -R; j <= R; j++)
                if (sqrt(i * i + j * j) < r)
                    b[(i + R) * M + j + R] = {1.0 / (sqrt(i * i + j * j) + 1), 0};
        fft(a, len, 1);
        fft(b, len, 1);
        for (int i = 0; i < len; i++) a[i] = a[i] * b[i];
        fft(a, len, -1);
        double ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans = max(ans, a[(i + R) * M + j + R].x);
        printf("%.3f\n", ans);
    }
}