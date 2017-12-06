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
                    (C[i][j] += A[i][k] * B[k][j]) %= p;
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

ll Pow(ll a, ll n, ll p)
{
    ll b = 1;
    for (; n; n >>= 1, (a *= a) %= p)
        if (n & 1) (b *= a) %= p;
    return b;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    ll a, b, n;
    while (~scanf("%lld%lld%lld", &a, &b, &n))
    {
        mat A(2, vec(2));
        A[0][0] = A[0][1] = A[1][0] = 1;
        if (n == 0)
            printf("%lld\n", a);
        else if (n == 1)
            printf("%lld\n", b);
        else
        {
            ll pa = Pow(A, n - 1, mod - 1)[1][0];
            ll pb = Pow(A, n, mod - 1)[1][0];
            // printf("pa = %lld\npb = %lld\n", pa, pb);
            ll ret = Pow(a, pa, mod) * Pow(b, pb, mod) % mod;
            printf("%lld\n", ret);
        }
    }
    return 0;
}
