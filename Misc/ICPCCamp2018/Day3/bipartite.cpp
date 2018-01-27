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

const int N = 1 << 18;
const int P = (479 << 21) + 1; //1004535809
const int G = 3;
ll wn[31];

ll Pow(ll a, ll n, ll mod)
{
    ll t = 1;
    for (; n; n >>= 1, a = (a * a % mod))
        if (n & 1) t = (t * a % mod);
    return t;
}

void GetWn()
{
    for (int i = 0; i < 31; i++)
    {
        int t = 1 << i;
        wn[i] = Pow(G, (P - 1) / t, P);
    }
}

void Rader(ll a[], int len)
{
    int j = len >> 1;
    for (int i = 1; i < len - 1; i++) {
        if (i < j) swap(a[i], a[j]);
        int k = len >> 1;
        while (j >= k) {
            j -= k;
            k >>= 1;
        }
        if (j < k) j += k;
    }
}

void NTT(ll a[], int len, int on)
{
    Rader(a, len);
    for (int h = 2, id = 0; h <= len; h <<= 1) {
        id++;
        for (int j = 0; j < len; j += h) {
            ll w = 1;
            for (int k = j; k < j + h / 2; k++) {
                ll u = a[k] % P;
                ll t = w * (a[k + h / 2] % P) % P;
                a[k] = (u + t) % P;
                a[k + h / 2] = ((u - t) % P + P) % P;
                w = w * wn[id] % P;
            }
        }
    }
    if (on == -1) {
        for (int i = 1; i < len / 2; i++)
            swap(a[i], a[len - i]);
        ll Inv = Pow(len, P - 2, P);
        for (int i = 0; i < len; i++) a[i] = a[i] % P * Inv % P;
    }
}

ll _a[1 << 20];
ll _b[1 << 20];
struct BigBin
{
    const int BITS = 8;
    const int D = 1 << BITS;
    int* num;
    int len;
    BigBin(unsigned short n = 0)
    {
        len = 1;
        num = new int[1];
        num[0] = n;
    }
    BigBin(const BigBin& b)
    {
        len = b.len;
        num = new int[len];
        for (int i = 0; i < len; i++)
            num[i] = b.num[i];
    }
    BigBin(int* a, int n)
    {
        len = n;
        num = new int[len];
        for (int i = 0; i < len; i++)
            num[i] = a[i];
    }
    BigBin(ll* a, int n)
    {
        len = n;
        num = new int[len];
        for (int i = 0; i < len; i++)
            num[i] = a[i];
    }
    ~BigBin()
    {
        delete[] num;
    }
    BigBin& operator=(const BigBin& b)
    {
        delete[] num;
        len = b.len;
        num = new int[len];
        for (int i = 0; i < len; i++)
            num[i] = b.num[i];
        return *this;
    }
    BigBin operator*(const BigBin& b)
    {
        int N = 1;
        while (N <= len + b.len + 1) N *= 2;
        for (int i = 0; i < N; i++) _a[i] = i < len ? num[i] : 0;
        for (int i = 0; i < N; i++) _b[i] = i < b.len ? b.num[i] : 0;
        NTT(_a, N, 1);
        NTT(_b, N, 1);
        for (int i = 0; i < N; i++) _a[i] = 1LL * _a[i] * _b[i] % P;
        NTT(_a, N, -1);
        ll c = 0;
        int l = 1;
        for (int i = 0; i < N; i++)
        {
            _a[i] += c;
            if (_a[i]) l = i + 1;
            c = _a[i] / D;
            _a[i] %= D;
        }
        return BigBin(_a, l);
    }
    BigBin operator+(const BigBin& b)
    {
        int l = max(len, b.len);
        int c = 0;
        for (int i = 0; i <= l; i++)
        {
            _a[i] = c;
            _a[i] += i < len ? num[i] : 0;
            _a[i] += i < b.len ? b.num[i] : 0;
            c = _a[i] / D;
            _a[i] %= D;
        }
        if (_a[l]) l++;
        return BigBin(_a, l);
    }
    void out()
    {
        int nz = 0;
        int cnt = 0;
        for (int i = len - 1; ~i; i--)
        {
            for (int j = BITS - 1; ~j; j--)
            {
                int x = num[i] >> j & 1;
                if (x || i + j == 0) nz = 1;
                if (nz)
                    if (x) cnt++;
            }
        }
        puts(cnt == 1 ? "Yes" : "No");
    }
};

BigBin A[18];

char s[200000];

int num[1 << 18];

BigBin solve(int* a, int L, int R)
{
    if (L == R) return BigBin(a[L]);
    int M = (L + R) >> 1;

    int len = R - L + 1;
    int t = __builtin_ctz(len) - 1;

    return solve(a, L, M) + solve(a, M + 1, R) * A[t];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    GetWn();
    A[0] = BigBin(10);
    for (int i = 0; i < 17; i++) A[i + 1] = A[i] * A[i];
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        if (s[0] == '-')
        {
            puts("No");
            continue;
        }
        int n = strlen(s);
        for (int i = 0; i < n; i++) s[i] -= '0';
        reverse(s, s + n);
        int N = 1;
        while (N <= n) N *= 2;
        for (int i = 0; i < N; i++) num[i] = i < n ? s[i] : 0;
        BigBin ans = solve(num, 0, N - 1);
        ans.out();
    }
    return 0;
}