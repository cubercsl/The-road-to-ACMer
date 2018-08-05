#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
typedef vector<int> vec;
typedef vector<vec> mat;

mat operator*(const mat& A, const mat& B)
{
    int n = A.size();
    mat ret(n, vec(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            ret[i][j] = INF;
            for (int k = 0; k < n; k++)
                ret[i][j] = min(ret[i][j], A[i][k] + B[k][j]);
        }
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        mat G(n, vec(n, INF));
        vector<mat> A(101, mat(n, vec(n))), B(101, mat(n, vec(n)));
        while (m--)
        {
            static int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            --u, --v;
            G[u][v] = min(G[u][v], w);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                A[0][i][j] = B[0][i][j] = i == j ? 0 : INF;
        for (int i = 1; i <= 100; i++) A[i] = A[i - 1] * G;
        for (int i = 1; i <= 100; i++) B[i] = B[i - 1] * A[100];
        for (int i = 0; i < n; i++) G[i][i] = 0;
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
        for (int i = 0; i <= 100; i++) A[i] = A[i] * G;
        int q;
        scanf("%d", &q);
        while (q--)
        {
            static int u, v, k;
            scanf("%d%d%d", &u, &v, &k);
            --u, --v;
            int a = k % 100, b = k / 100;
            int ans = INF;
            for (int i = 0; i < n; i++) ans = min(ans, A[a][u][i] + B[b][i][v]);
            if (ans >= INF) ans = -1;
            printf("%d\n", ans);
        }
    }
}