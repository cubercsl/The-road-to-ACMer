#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 9;
const int M = 1 << 18;
const int mod = 119 << 23 | 1;
typedef long long ll;
typedef vector<int> Vector;
typedef vector<Vector> Matrix;

int f[M], inv[M];

int Pow(int a, int n = mod - 2)
{
    int t = 1;
    for (; n; n >>= 1, a = 1LL * a * a % mod)
        if (n & 1) t = 1LL * t * a % mod;
    return t;
}

int det(Matrix mat)
{
    int n = mat.size();
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            while (mat[j][i])
            {
                int t = 1LL * mat[i][i] * Pow(mat[j][i]) % mod;
                for (int k = i; k < n; k++)
                    mat[i][k] = (mat[i][k] - 1LL * mat[j][k] * t % mod) % mod;
                swap(mat[i], mat[j]);
                ans = -ans;
            }
        ans = 1LL * ans * mat[i][i] % mod;
        if (!ans) return 0;
    }
    return (ans + mod) % mod;
}

void work(int m)
{
    Matrix d(m, Vector(m));
    Matrix Kirchhoff(m, Vector(m));
    vector<int> in(m), out(m), vis(m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) scanf("%d", &d[i][j]);
    for (int i = 0; i < m; i++) in[i] = out[i];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
        {
            in[j] += d[i][j];
            out[i] += d[i][j];
            Kirchhoff[i][j] -= d[i][j];
            Kirchhoff[i][i] += d[i][j];
        }
    for (int i = 0; i < m; i++)
        if (in[i] != out[i]) return (void)puts("0");
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < m; v++)
            if (d[u][v] && !vis[v]) q.push(v), vis[v] = 1;
    }
    for (int i = 0; i < m; i++)
        if (vis[i] == 0) return (void)puts("0");
    Kirchhoff.pop_back();
    for (auto& vec : Kirchhoff) vec.pop_back();
    int ans = det(Kirchhoff);
    if (ans)
    {
        ans = ans * 1LL * f[out[0]] % mod;
        for (int i = 1; i < m; i++) ans = 1LL * ans * f[out[i] - 1] % mod;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                ans = 1LL * ans * inv[d[i][j]] % mod;
    }
    printf("%d\n", ans);
}

int main()
{
    f[0] = 1;
    for (int i = 1; i < M; i++) f[i] = 1LL * f[i - 1] * i % mod;
    inv[M - 1] = Pow(f[M - 1]);
    for (int i = M - 2; ~i; i--) inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
    int m, kase = 0;
    while (~scanf("%d", &m)) printf("Case #%d: ", ++kase), work(m);
}