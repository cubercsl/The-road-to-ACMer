#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

const int mod = 1e9 + 7;
mat mul(mat& A, mat& B)
{
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++)
        for (int k = 0; k < B.size(); k++)
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

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll a, b, c, d, p, n;
        scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &p, &n);
        if (n == 1)
        {
            printf("%lld\n", a);
            continue;
        }
        if (n == 2)
        {
            printf("%lld\n", b);
            continue;
        }
        mat A = {{d, c, 0}, {1, 0, 0}, {0, 0, 1}};
        ll q;
        mat S = {{b, 0, 0}, {a, 0, 0}, {1, 0, 0}};
        mat B = mat(3, vec(3));
        if (n <= p)
        {
            for (ll l = 3, r; l <= n; l = r + 1)
            {
                r = p / (p / l);
                r = min(r, n);
                q = p / l;
                A[0][2] = q;
                B = Pow(A, (r - l + 1));
                S = mul(B, S);
            }
        }
        else
        {
            for (ll l = 3, r; l <= n; l = r + 1)
            {
                if (l > p)
                    r = n;
                else
                    r = p / (p / l);
                q = p / l;
                A[0][2] = q;
                mat B = Pow(A, (r - l + 1));
                S = mul(B, S);
            }
        }
        printf("%lld\n", S[0][0]);
    }
}