#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
int a[N], b[N];
bool vis[N];

void dfs(int* a, int u, int& cnt)
{
    vis[u] = true;
    cnt++;
    if (!vis[a[u]]) dfs(a, a[u], cnt);
}

vector<int> solve(int* a, int n)
{
    vector<int> ans;
    for (int i = 0; i < n; i++) vis[i] = 0;
    for (int i = 0; i < n; i++)
        if (!vis[i])
        {
            int cnt = 0;
            dfs(a, i, cnt);
            ans.push_back(cnt);
        }
    return ans;
}

typedef long long ll;
const int mod = 1e9 + 7;

void debug(const vector<int>& x)
{
    for (auto& t : x) cerr << t << ' ';
    cerr << endl;
}

int main()
{
    int n, m, kase = 0;
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 0; i < n; i++) scanf("%d", a + i);
        for (int i = 0; i < m; i++) scanf("%d", b + i);
        auto xx = solve(a, n);
        auto yy = solve(b, m);
        ll ans = 1;
        // debug(xx);
        // debug(yy);
        for (auto& x : xx)
        {
            ll tmp = 0;
            for (auto& y : yy)
            {
                if (x % y == 0) tmp += y;
            }
            (ans *= tmp) %= mod;
        }
        printf("Case #%d: %lld\n", ++kase, ans);
    }
}