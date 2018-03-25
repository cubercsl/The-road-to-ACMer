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
//复数结构体
struct Complex
{
    double x, y; //实部和虚部 x+yi
    Complex(double _x = 0.0, double _y = 0.0) { x = _x, y = _y; }
    Complex operator-(const Complex& b) const { return Complex(x - b.x, y - b.y); }
    Complex operator+(const Complex& b) const { return Complex(x + b.x, y + b.y); }
    Complex operator*(const Complex& b) const { return Complex(x * b.x - y * b.y, x * b.y + y * b.x); }
};
/*
* 进行FFT和IFFT前的反转变换。
* 位置i和 （i二进制反转后位置）互换
* len必须取2的幂
*/
void change(Complex y[], int len)
{
    for (int i = 1, j = len / 2; i < len - 1; i++)
    {
        if (i < j) swap(y[i], y[j]);
        //交换互为小标反转的元素，i<j保证交换一次
        //i做正常的+1，j左反转类型的+1,始终保持i和j是反转的
        int k = len / 2;
        while (j >= k) j -= k, k /= 2;
        if (j < k) j += k;
    }
}
/*
* 做FFT
* len必须为2^k形式，
* on==1时是DFT，on==-1时是IDFT
*/
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

Complex A[1 << 15], B[1 << 15];
int a[1 << 15], b[1 << 15];

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
        clr(a, 0), clr(b, 0);
        int n, m, num;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num);
            a[num]++;
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &num);
            b[num]++;
        }
        int len = 1 << 15;
        for (int i = 0; i < len; i++)
            A[i] = Complex(a[i], 0), B[i] = Complex(b[i], 0);
        fft(A, len, 1);
        fft(B, len, 1);
        for (int i = 0; i < len; i++) A[i] = A[i] * B[i];
        fft(A, len, -1);
        ll ans = 0;
        for (int i = 0; i < len; i += 3) ans += (ll)(A[i].x + 0.5);
        for (int i = 0; i < len; i += 7) ans += (ll)(A[i].x + 0.5);
        for (int i = 0; i < len; i += 21) ans -= (ll)(A[i].x + 0.5);
        printf("%lld\n", ans);
    }
    return 0;
}
