// Super Poker II, UVa 12298

/*Sample Input
12 20 2
4S 6H
0 0 0
*/

#include <bits/stdc++.h>
using namespace std;

const long double PI = acos(-1.0);
//复数结构体
struct Complex
{
    long double x, y; //实部和虚部 x+yi
    Complex(long double _x = 0.0, long double _y = 0.0)
    {
        x = _x;
        y = _y;
    }
    Complex operator-(const Complex &b) const
    {
        return Complex(x - b.x, y - b.y);
    }
    Complex operator+(const Complex &b) const
    {
        return Complex(x + b.x, y + b.y);
    }
    Complex operator*(const Complex &b) const
    {
        return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
    }
};
/*
* 进行FFT和IFFT前的反转变换。
* 位置i和 （i二进制反转后位置）互换
* len必须取2的幂
*/
void change(Complex y[], int len)
{
    int i, j, k;
    for (i = 1, j = len / 2; i < len - 1; i++)
    {
        if (i < j)
            swap(y[i], y[j]);
        //交换互为小标反转的元素，i<j保证交换一次
        //i做正常的+1，j左反转类型的+1,始终保持i和j是反转的
        k = len / 2;
        while (j >= k)
        {
            j -= k;
            k /= 2;
        }
        if (j < k)
            j += k;
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

bool is_Prime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

const int MAXN = 1 << 19;
long long sum[MAXN];
Complex S[MAXN], H[MAXN], C[MAXN], D[MAXN];
bool isPrime[50005]; //素数
int main()
{
    isPrime[0] = isPrime[1] = 1;
    for (int i = 2; i < 50005; i++)
        isPrime[i] = is_Prime(i);
    // 预处理：打素数表
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c), a + b + c)
    {
        int n;
        char tr;
        int len = 1;
        while ((b << 2) >= len)
            len <<= 1;
        for (int i = 0; i < len; i++)
            S[i] = H[i] = C[i] = D[i] = Complex(0, 0);
        for (int i = 0; i <= b; i++)
            if (!isPrime[i])
                S[i] = H[i] = C[i] = D[i] = Complex(1, 0);
        // 初始化
        for (int i = 0; i < c; i++)
        {
            scanf("%d%c", &n, &tr);
            // cin >> n >> tr;
            switch (tr)
            {
            case 'S':
                S[n] = Complex(0, 0);
                break;
            case 'H':
                H[n] = Complex(0, 0);
                break;
            case 'C':
                C[n] = Complex(0, 0);
                break;
            case 'D':
                D[n] = Complex(0, 0);
                break;
            }
        }
        fft(S, len, 1);
        fft(H, len, 1);
        fft(C, len, 1);
        fft(D, len, 1);
        // 快速傅里叶变换 系数转点值

        for (int i = 0; i < len; i++)
            S[i] = S[i] * H[i] * C[i] * D[i];
        // O(n)做乘法

        fft(S, len, -1);
        // 快速傅里叶变换 点值转系数
        for (int i = a; i <= b; i++)
            printf("%lld\n", (long long)(S[i].x + 0.5));
        printf("\n");
    }
    return 0;
}
