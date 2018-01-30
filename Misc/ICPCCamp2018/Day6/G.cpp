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

typedef vector<ll> vec;
typedef vector<vec> mat;
mat mul(mat& A, mat& B, ll p)
{
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++)
        for (int k = 0; k < B.size(); k++)
            if (A[i][k]) // 对稀疏矩阵的优化
                for (int j = 0; j < B[0].size(); j++)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % p;
    return C;
}
mat Pow(mat A, ll n, ll p)
{
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); i++) B[i][i] = 1;
    for (; n; n >>= 1, A = mul(A, A, p))
        if (n & 1) B = mul(B, A, p);
    return B;
}

const int maxn = 1e6 + 5;
bool vis[maxn];
int tot, phi[maxn], prime[maxn];
void CalPhi(int n)
{
    clr(vis, 0);
    phi[1] = 1;
    tot = 0;
    for (int i = 2; i < n; i++)
    {
        if (!vis[i])
            prime[tot++] = i, phi[i] = i - 1;
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] > n) break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}

ll Pow(ll a, ll n, ll p)
{
    a %= p;
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= p)
        if (n & 1) (t *= a) %= p;
    return t;
}

bool judge(ll a, ll p) { return Pow(a, (p - 1) >> 1, p) == 1; }

ll fac[5005][2];
int getFactors(ll x)
{
    int cnt = 0;
    for (int i = 0; prime[i] <= x / prime[i]; i++)
    {
        fac[cnt][1] = 0;
        if (x % prime[i] == 0)
        {
            fac[cnt][0] = prime[i];
            while (x % prime[i] == 0) fac[cnt][1]++, x /= prime[i];
            cnt++;
        }
    }
    if (x != 1) fac[cnt][0] = x, fac[cnt++][1] = 1;
    return cnt;
}

ll fact[5005];
int work(ll n)
{
    int cnt = 0;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i * i == n)
                fact[cnt++] = i;
            else
            {
                fact[cnt++] = i;
                fact[cnt++] = n / i;
            }
        }
    }
    return cnt;
}

ll solve(ll n)
{
    ll ans = 1;
    mat A(2, vec(2));
    A[0][0] = A[0][1] = A[1][0] = 1, A[1][1] = 0;
    int cnt = getFactors(n);
    for (int i = 0; i < cnt; i++)
    {
        ll p = fac[i][0];
        ll ret = 1;
        if (p == 2)
            ret = 3;
        else if (p == 3)
            ret = 8;
        else if (p == 5)
            ret = 20;
        else
        {
            int m;
            bool tmp = judge(5, p);
            if (tmp)
                m = work(p - 1);
            else
                m = work(2LL * (p + 1));
            sort(fact, fact + m);
            for (int j = 0; j < m; j++)
            {
                mat B = Pow(A, fact[j] - 1, p);
                ll x = (B[0][0] + B[0][1]) % p;
                ll y = (B[1][0] + B[1][1]) % p;
                if (x == 1 && y == 0)
                {
                    ret = fact[j];
                    break;
                }
            }
        }
        for (int j = 1; j < fac[i][1]; j++) ret *= fac[i][0];
        ans = ans / __gcd(ans, ret) * ret;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    CalPhi(maxn);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll n;
        scanf("%lld", &n);
        printf("%lld\n", solve(n));
    }
    return 0;
}
