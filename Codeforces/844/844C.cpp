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

const int N = 1 << 17;
int a[N], b[N];
VI G[N];
bool vis[N];

void dfs(int id, int num)
{
    G[num].pb(id);
    vis[id] = 1;
    if (!vis[a[id]]) dfs(a[id], num);
}

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
            G[i].clear();
        }
        clr(vis, 0);
        sort(b, b + n);
        for (int i = 0; i < n; i++) a[i] = lower_bound(b, b + n, a[i]) - b;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (!vis[i]) dfs(i, cnt++);
        cout << cnt << endl;
        for (int i = 0; i < cnt; i++)
        {
            cout << G[i].size();
            for (auto t : G[i])
                cout << " " << t + 1;
            cout << endl;
        }
    }
    return 0;
}