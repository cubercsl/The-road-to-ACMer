#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;

const int maxn = 2005;

struct TwoSAT
{
    int n;
    vector<int> G[maxn << 1];
    bool mark[maxn << 1];
    int S[maxn << 1], c;
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < (n << 1); i++) G[i].clear();
        clr(mark, 0);
    }
    bool dfs(int x)
    {
        if (mark[x ^ 1]) return false;
        if (mark[x]) return true;
        mark[x] = true;
        S[c++] = x;
        for (int i = 0; i < G[x].size(); i++)
            if (!dfs(G[x][i])) return false;
        return true;
    }
    //x = xval or y = yval
    void add_clause(int x, int xval, int y, int yval)
    {
        x = (x << 1) + xval;
        y = (y << 1) + yval;
        G[x ^ 1].pb(y);
        G[y ^ 1].pb(x);
    }
    bool solve()
    {
        for (int i = 0; i < (n << 1); i += 2)
            if (!mark[i] && !mark[i + 1])
            {
                c = 0;
                if (!dfs(i))
                {
                    while (c > 0) mark[S[--c]] = false;
                    if (!dfs(i + 1)) return false;
                }
            }
        return true;
    }
};

int n, T[maxn][2];

TwoSAT solver;

bool test(int diff)
{
    solver.init(n);
    for (int i = 0; i < n; i++)
        for (int a = 0; a < 2; a++)
            for (int j = i + 1; j < n; j++)
                for (int b = 0; b < 2; b++)
                    if (abs(T[i][a] - T[j][b]) < diff)
                        solver.add_clause(i, a ^ 1, j, b ^ 1);
    return solver.solve();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (scanf("%d", &n) == 1 && n)
    {
        int L = 0, R = 0;
        for (int i = 0; i < n; i++)
            for (int a = 0; a < 2; a++)
            {
                scanf("%d", &T[i][a]);
                R = max(R, T[i][a]);
            }
        while (L < R)
        {
            int M = L + (R - L + 1) / 2;
            if (test(M)) L = M;
            else R = M - 1;
        }
        printf("%d\n", L);
    }

    return 0;
}
