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

const int maxn = 3005;

const int N = 2e6 + 5;
bool notprime[N] = {1, 1};
void GetPrime()
{
    for (int i = 2; i < N; i++)
        if (!notprime[i] && i <= N / i)
            for (int j = i * i; j < N; j += i)
                notprime[j] = 1;
}

int a[maxn];

struct Match
{
    int n;
    vector<int> G[maxn];
    int linker[maxn];
    bool vis[maxn];
    inline void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
    }
    inline void addedge(int u, int v) { G[u].pb(v); }
    bool dfs(int u)
    {
        for (auto v : G[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                if (linker[v] == -1 || dfs(linker[v]))
                {
                    linker[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
    int MaxMatch()
    {
        int ans = 0;
        clr(linker, -1);
        for (int u = 0; u < n; u++)
        {
            clr(vis, 0);
            if (dfs(u)) ans++;
        }
        return ans;
    }
    bool mark[maxn];
    int solve(int n, int k)
    {
        clr(mark, 0);
        int match = MaxMatch();
        int ans = min(k, match);
        match = ans;
        for (int i = 0; i < n; i++)
            if (linker[i] != -1)
                mark[i] = mark[linker[i]] = 1;
        ans <<= 1;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (match < k && a[i] == 1 && a[j] == 1 && mark[i] == 0 && mark[j] == 0)
                    match++, ans += 2, mark[i] = mark[j] = 1;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (match < k && !notprime[a[i] + a[j]] && (mark[i] ^ mark[j]))
                    match++, ans++, mark[i] = mark[j] = 1;
        return ans;
    }
} gao;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    GetPrime();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        gao.init(n);
        for (int i = 0; i < n; i++) scanf("%d", a + i);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (!notprime[a[i] + a[j]] && (a[i] != 1 || a[j] != 1))
                {
                    if (a[i] & 1)
                        gao.addedge(i, j);
                    else
                        gao.addedge(j, i);
                }
        printf("%d\n", gao.solve(n, k));
    }
    return 0;
}
