// 3-idiots, HDU4609

/*Sample Input
2
4
1 3 3 4
4
2 3 3 4
*/

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
    Complex(double x = 0.0, double y = 0.0) { this->x = x, this->y = y; }
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
        for (int i = 0; i < len; i++) y[i].x /= len;
}

const int maxn = 1e5 + 10;
Complex x1[maxn << 2];
int a[maxn];
ll num[maxn << 2];
ll sum[maxn << 2];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            num[a[i]]++;
        }
        sort(a, a + n);
        int len1 = a[n - 1] + 1;
        int len = 1;
        while (len < 2 * len1) len <<= 1;
        for (int i = 0; i < len1; i++) x1[i] = Complex(num[i], 0);
        for (int i = len1; i < len; i++) x1[i] = Complex(0, 0);
        fft(x1, len, 1);
        for (int i = 0; i < len; i++) x1[i] = x1[i] * x1[i];
        fft(x1, len, -1);
        for (int i = 0; i < len; i++) num[i] = (ll)(x1[i].x + 0.5);
        len = 2 * a[n - 1];
        for (int i = 0; i < n; i++) num[a[i] + a[i]]--; // 去重
        for (int i = 1; i <= len; i++) num[i] /= 2;     // 去序
        sum[0] = 0;
        for (int i = 1; i <= len; i++) sum[i] = sum[i - 1] + num[i];
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += sum[len] - sum[a[i]]; // 一个取大，一个取小
            cnt -= (ll)(n - 1 - i) * i;  // 一个取本身
            cnt -= (n - 1);              // 两个取大
            cnt -= (ll)(n - 1 - i) * (n - i - 2) / 2;
        }
        ll tot = (ll)n * (n - 1) * (n - 2) / 6;
        printf("%.7lf\n", (double)cnt / tot);
    }
    return 0;
}
