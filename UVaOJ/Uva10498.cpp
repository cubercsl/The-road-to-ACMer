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
// const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
// const double eps = 1e-6;

const int maxm = 500; // 约束数目上限
const int maxn = 500; // 变量数目上限
const double INF = 1e100;
const double eps = 1e-10;

struct Simplex
{
    int n;                // 变量个数
    int m;                // 约束个数
    double a[maxm][maxn]; // 输入矩阵
    int B[maxm], N[maxn]; // 算法辅助变量

    void pivot(int r, int c)
    {
        swap(N[c], B[r]);
        a[r][c] = 1 / a[r][c];
        for (int j = 0; j <= n; j++)
            if (j != c) a[r][j] *= a[r][c];
        for (int i = 0; i <= m; i++)
            if (i != r)
            {
                for (int j = 0; j <= n; j++)
                    if (j != c) a[i][j] -= a[i][c] * a[r][j];
                a[i][c] = -a[i][c] * a[r][c];
            }
    }

    bool feasible()
    {
        for (;;)
        {
            int r, c;
            double p = INF;
            for (int i = 0; i < m; i++)
                if (a[i][n] < p) p = a[r = i][n];
            if (p > -eps) return true;
            p = 0;
            for (int i = 0; i < n; i++)
                if (a[r][i] < p) p = a[r][c = i];
            if (p > -eps) return false;
            p = a[r][n] / a[r][c];
            for (int i = r + 1; i < m; i++)
                if (a[i][c] > eps)
                {
                    double v = a[i][n] / a[i][c];
                    if (v < p) r = i, p = v;
                }
            pivot(r, c);
        }
    }

    // 解有界返回1，无解返回0，无界返回-1。b[i]为x[i]的值，ret为目标函数的值
    int simplex(int n, int m, double x[maxn], double& ret)
    {
        this->n = n, this->m = m;
        for (int i = 0; i < n; i++) N[i] = i;
        for (int i = 0; i < m; i++) B[i] = n + i;
        if (!feasible()) return 0;
        for (;;)
        {
            int r, c;
            double p = 0;
            for (int i = 0; i < n; i++)
                if (a[m][i] > p) p = a[m][c = i];
            if (p < eps)
            {
                for (int i = 0; i < n; i++)
                    if (N[i] < n) x[N[i]] = 0;
                for (int i = 0; i < m; i++)
                    if (B[i] < n) x[B[i]] = a[i][n];
                ret = -a[m][n];
                return 1;
            }
            p = INF;
            for (int i = 0; i < m; i++)
                if (a[i][c] > eps)
                {
                    double v = a[i][n] / a[i][c];
                    if (v < p) r = i, p = v;
                }
            if (p == INF) return -1;
            pivot(r, c);
        }
    }
} gao;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 0; i < n; i++) scanf("%lf", &gao.a[m][i]);
        gao.a[m][n] = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n + 1; j++) scanf("%lf", &gao.a[i][j]);
        double ans, x[maxn];
        gao.simplex(n, m, x, ans);
        ans *= m;
        printf("Nasa can spend %d taka.\n", (int)floor(ans + 1 - eps));
    }
    return 0;
}
