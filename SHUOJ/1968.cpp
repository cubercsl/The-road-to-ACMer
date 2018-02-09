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

void fmt(VI& a)
{
    int n = a.size();
    int m = __builtin_ctz(n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (!(j >> i & 1)) (a[j | (1 << i)] += a[j]) %= mod;
}

void ifmt(VI& a)
{
    int n = a.size();
    int m = __builtin_ctz(n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (!(j >> i & 1)) ((a[j | (1 << i)] -= a[j]) += mod) %= mod;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int N;
    while (~scanf("%d", &N))
    {
        int n = 1;
        while (n < N) n <<= 1;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < N; i++) scanf("%d", &a[i]);
        for (int i = 0; i < N; i++) scanf("%d", &b[i]);
        /*
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                (c[i | j] += 1LL * a[i] * b[j] % mod) %= mod;
        for (int i = 0; i < N; i++) printf("%d%c", c[i], i == N - 1 ? '\n' : ' ');
        */
        fmt(a), fmt(b);
        for (int i = 0; i < n; i++) a[i] = (1LL * a[i] * b[i]) % mod;
        ifmt(a);
        for (int i = 0; i < N; i++) printf("%d%c", a[i], i == N - 1 ? '\n' : ' ');
        
    }
    return 0;
}
