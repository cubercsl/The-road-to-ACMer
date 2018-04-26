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

string cur = "SPRLK";
string win[] = {"PL", "RK", "LS", "KP", "SR"};
const int maxn = 1 << 20;
Complex A[maxn], B[maxn];
int sum[maxn];

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
    while (n <= (a + b)) n <<= 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < n; j++) A[j] = (j < a && (s[j] == win[i][0] || s[j] == win[i][1])) ? Complex(1, 0) : Complex(0, 0);
        for (int j = 0; j < n; j++) B[j] = (j < b && t[j] == cur[i]) ? Complex(1, 0) : Complex(0, 0);
        // for (int j = 0; j < n; j++) printf("%.0f%c", A[j].x, " \n"[j == n - 1]);
        // for (int j = 0; j < n; j++) printf("%.0f%c", B[j].x, " \n"[j == n - 1]);
        fft(A, n, 1), fft(B, n, 1);
        for (int j = 0; j < n; j++) A[j] = A[j] * B[j];
        fft(A, n, -1);
        for (int j = 0; j < a - b + 1; j++) sum[j] += (int)(A[b + j - 1].x + 0.5);
        // for (int j = 0; j < a - b + 1; j++) printf("%d%c", sum[j], " \n"[j == a - b]);
    }
    int ans = 0;
    for (int i = 0; i < a - b + 1; i++) ans = max(ans, sum[i]);
    cout << ans << endl;
    return 0;
}
