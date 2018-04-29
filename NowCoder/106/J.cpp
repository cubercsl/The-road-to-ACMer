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

const int N = 1 << 20;
int vis[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int a, b;
    clr(vis, -1);
    cin >> a >> b;
    queue<int> q;
    vis[a] = 0;
    q.push(a);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x > 0 && vis[x - 1] < 0) vis[x - 1] = vis[x] + 1, q.push(x - 1);
        if (x + 1 < N && vis[x + 1] < 0) vis[x + 1] = vis[x] + 1, q.push(x + 1);
        if (x < 1) continue;
        int y = __builtin_popcount(x);
        if (x - y >= 0 && vis[x - y] < 0) vis[x - y] = vis[x] + 1, q.push(x - y);
        if (x + y < N && vis[x + y] < 0) vis[x + y] = vis[x] + 1, q.push(x + y);
    }
    cout << vis[b] << endl;
    return 0;
}
