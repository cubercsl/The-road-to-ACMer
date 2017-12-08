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

const int maxn = 1e6 + 5;
bool notprime[maxn] = {1, 1}; // 0 && 1 为非素数
int prime[maxn], tot;
void GetPrime()
{
    for (int i = 2; i < maxn; i++)
        if (!notprime[i] && i <= maxn / i) // 筛到√n为止
            for (int j = i * i; j < maxn; j += i)
                notprime[j] = 1;
    tot = 0;
    for (int i = 2; i < maxn; i++)
        if (!notprime[i]) prime[tot++] = i;
}

int a[3005];

const int N = 1 << 17;
vector<int> G[N];
int linker[N];
bool used[N];
inline void init(int n)
{
    for (int i = 0; i < n; i++) G[i].clear();
}
inline void addedge(int u, int v) { G[u].pb(v); }
bool dfs(int u)
{
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (!used[v])
        {
            used[v] = true;
            if (linker[v] == -1 || dfs(linker[v]))
            {
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}
int hungary(int n)
{
    int ans = 0;
    clr(linker, -1);
    for (int u = 0; u < n; u++)
    {
        clr(used, 0);
        if (dfs(u))
            ans++;
        else
            return ans;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    GetPrime();
    // for (int i = 0; i < 10; i++) cout << prime[i] << endl;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < tot; j++)
            if (a[i] % prime[j] == 0)
                v.pb(prime[j]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v.size(); j++)
            if (a[i] % v[j] == 0)
                addedge(i, j);
    }
    printf("%d\n", hungary(n));
    return 0;
}
