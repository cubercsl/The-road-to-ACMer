#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
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
mat mul(mat& A, mat& B)
{
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++)
        for (int k = 0; k < B.size(); k++)
            if (A[i][k]) // 对稀疏矩阵的优化
                for (int j = 0; j < B[0].size(); j++)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    return C;
}
mat Pow(mat A, ll n)
{
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); i++) B[i][i] = 1;
    for (; n; n >>= 1, A = mul(A, A))
        if (n & 1) B = mul(B, A);
    return B;
}

ll c[] = {1, 0, 8, 4, 2, 1};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    mat A(6, vec(6));
    A = {{1, 1, 1, 1, 1, 1},
         {1, 0, 0, 0, 0, 0},
         {0, 0, 1, 3, 3, 1},
         {0, 0, 0, 1, 2, 1},
         {0, 0, 0, 0, 1, 1},
         {0, 0, 0, 0, 0, 1}};
    scanf("%d", &T);
    while (T--)
    {
        ll n;
        scanf("%lld", &n);
        mat B = Pow(A, n - 1);
        ll ans = 0;
        for (int i = 0; i < 6; i++) (ans += (B[0][i] * c[i] % mod)) %= mod;
        printf("%lld\n", ans);
    }
    return 0;
}