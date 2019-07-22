#include <bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr, ##__VA_ARGS__)

const int mod = 1e9 + 7;

vector<int> f;

void fwt(vector<int>& f, int m)
{
    int n = __builtin_ctz(m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (j & (1 << i))
            {
                int l = f[j ^ (1 << i)], r = f[j];
                f[j ^ (1 << i)] = (l + r) % mod, f[j] = (l - r + mod) % mod;
            }
}

int Pow(int a, int n)
{
    int t = 1;
    for (; n; n >>= 1, a = 1LL * a * a % mod)
        if (n & 1) t = 1LL * t * a % mod;
    return t;
}
void dfs(const vector<int>& a, int x, int v, int p)
{
    if (x == a.size())
    {
        f[v] += p;
        return;
    }
    dfs(a, x + 1, a[x] ^ v, -p);
    dfs(a, x + 1, v, p);
};
int main()
{
    int n, m, k;
    while (~scanf("%d%d%d", &n, &m, &k))
    {
        f.assign(1 << k, 0);
        for (int i = 0; i < n; i++)
        {
            vector<int> a(m);
            for (int j = 0; j < m; j++) scanf("%d", &a[j]);
            dfs(a, 0, 0, 1);
        }
        fwt(f, 1 << k);
        int ans = 0;
        int t = 1;
        int inv = Pow(1 << m, mod - 2);
        for (int i = 0; i < (1 << k); i++)
        {
            ans ^= 1LL * f[i] * t % mod * inv % mod;
            t = 3LL * t % mod;
        }
        printf("%d\n", ans);
    }
}