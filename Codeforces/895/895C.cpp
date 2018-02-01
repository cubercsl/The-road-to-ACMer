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

const int maxn = 510;
const int maxp = 2010;
const int N = 1e5 + 7;
int prime[maxp], vis[N];
void seive(int n)
{
    int m = (int)sqrt(n + 0.5);
    memset(vis, 0, sizeof(vis));
    for (int i = 2; i <= m; i++)
        if (!vis[i])
            for (int j = i * i; j <= n; j += i) vis[j] = 1;
}

int getprime(int n)
{
    seive(n);
    int c = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) prime[c++] = i;
    }
    return c;
}

ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

int A[maxn][maxn]; //系数矩阵
int solve(int m, int n)
{
    int i = 0, j = 0, k, r, u;
    while (i < m && j < n)
    {
        r = i;
        for (k = i; k < m; k++)
            if (A[k][j]) {
                r = k;
                break;
            }
        if (A[r][j])
        {
            if (r != i)
                for (k = 0; k <= n; k++) swap(A[r][k], A[i][k]);
            for (u = i + 1; u < m; u++)
                if (A[u][j])
                    for (k = i; k <= n; k++) A[u][k] ^= A[i][k];
            i++;
        }
        j++;
    }
    return i;
}
int main()
{
    int m = getprime(2010);

    int n, maxp = 0;
    ll x;
    scanf("%d", &n);
    memset(A, 0, sizeof(A));
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &x);
        for (int j = 0; j < m; j++)
        {
            while (x % prime[j] == 0) {
                maxp = max(maxp, j);
                x /= prime[j];
                A[j][i] ^= 1;
            }
        }
    }
    ll r = solve(maxp + 1, n);
    ll tmp = n - r;
    ll ans = Pow(2, tmp) - 1;
    printf("%lld\n", ans);
    return 0;
}
