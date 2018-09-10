#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

mat mul(const mat& A, const mat& B)
{
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++)
        for (int k = 0; k < B.size(); k++)
            if (A[i][k])
                for (int j = 0; j < B[0].size(); j++)
                    C[i][j] ^= (A[i][k] & B[k][j]);
    return C;
}
mat Pow(mat A, long long n)
{
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); i++) B[i][i] = 1;
    for (; n; n >>= 1, A = mul(A, A))
        if (n & 1) B = mul(B, A);
    return B;
}

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
        int n, m, t;
        scanf("%d%d%d", &n, &m, &t);
        mat b(m, vec(m));
        mat a(1, vec(n * n));
        for (int i = 0; i < n * n; i++)
        {
            scanf("%d", &a[0][i]);
            a[0][i] &= 1;
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &b[i][j]);
                b[i][j] &= 1;
            }
        m >>= 1;
        mat tr(n * n, vec(n * n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int p = max(i - m, 0); p <= min(i + m, n - 1); p++)
                    for (int q = max(j - m, 0); q <= min(j + m, n - 1); q++)
                        tr[p * n + q][i * n + j] = b[p - i + m][q - j + m];
        a = mul(a, Pow(tr, t));
        printf("%d\n", accumulate(a[0].begin(), a[0].end(), 0));
    }
    return 0;
}
