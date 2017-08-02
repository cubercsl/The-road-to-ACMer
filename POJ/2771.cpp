// Guardian of Decency, POJ2771

/*Sample Input
2
4
35 M classicism programming
0 M baroque skiing
43 M baroque chess
30 F baroque soccer
8
27 M romance programming
194 F baroque programming
67 M baroque ping-pong
51 M classicism programming
80 M classicism Paintball
35 M baroque ping-pong
39 F romance ping-pong
110 M romance Paintball
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
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

const int maxn = 1005;
int n;
vector<int> G[maxn];
int match[maxn];
bool vis[maxn];

struct node
{
    int h;
    bool sex;
    string music, sport;
} st[maxn];

void addedge(int u, int v)
{
    G[u].pb(v);
    G[v].pb(u);
}

bool dfs(int v)
{
    vis[v] = true;
    for (int i = 0; i < G[v].size(); i++)
    {
        int u = G[v][i], w = match[u];
        if (w < 0 || !vis[w] && dfs(w))
        {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int hungary()
{
    int ans = 0;
    clr(match, -1);
    for (int v = 0; v < n; v++)
    {
        if (match[v] < 0)
        {
            clr(vis, 0);
            if (dfs(v))
                ans++;
        }
    }
    return ans;
}

bool check(int x, int y)
{
    node a = st[x];
    node b = st[y];
    if (a.sex == b.sex) return false;
    if (a.h - b.h > 40 || b.h - a.h > 40) return false;
    if (a.music != b.music) return false;
    if (a.sport == b.sport) return false;
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
        cin >> n;
        for (int i = 0; i < n; i++)
            G[i].clear();
        for (int i = 0; i < n; i++)
        {
            char s[5];
            cin >> st[i].h >> s;
            if (s[0] != 'M')
                st[i].sex = 1;
            else
                st[i].sex = 0;
            cin >> st[i].music >> st[i].sport;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
                if (check(i, j))
                    addedge(i, j);
        }
        cout << n - hungary() << endl;
    }
    return 0;
}
