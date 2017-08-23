// FFF at Valentine, 2017 Multi-University Training Contest, HDU6165

/*Sample Input
3
5 5
1 2
2 3
2 4
3 5
4 5

3 3
1 2
2 3
3 1

5 5
1 2
2 3
3 1
3 4
4 5
*/

#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 1e3 + 5;
bool link[maxn][maxn];
vector<int> G[maxn];
bool vis[maxn];

void bfs(int s)
{
    clr(vis, 0);
    queue <int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto &y : G[x])
        {
            if (vis[y]) continue;
            link[s][y] = 1;
            q.push(y);
            vis[y] = 1;
        }
    }
}

bool ok(int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1 ; j < n; j++)
            if (!link[i][j] && !link[j][i])
                return false;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) G[i].clear();
        clr(link, 0);
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            G[u - 1].pb(v - 1);
        }
        for (int i = 0; i < n; i++)
            bfs(i);
        puts(ok(n) ? "I love you my love and our love save us!" : "Light my fire!");
    }
    return 0;
}
