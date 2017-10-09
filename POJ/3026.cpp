// Borg Maze, POJ3026

/*Sample Input
2
6 5
#####
#A#A##
# # A#
#S  ##
#####
7 7
#####
#AAA###
#    A#
# S ###
#     #
#AAA###
#####
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
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

const int maxn = 55;
string maze[maxn];
map<PII, int> M;
int tx[] = { -1, 0, 1, 0 };
int ty[] = { 0, -1, 0, 1 };
typedef pair<int, PII> Edge;
vector<Edge> edges;
inline void addedge(int u, int v, int w)
{
    edges.pb(mp(w, mp(u, v)));
}
void bfs(PII S, int n, int m)
{
    int s = M[S];
    int vis[maxn][maxn];
    clr(vis, -1);
    queue<PII> q;
    q.push(S);
    vis[S.X][S.Y] = 0;
    while (!q.empty())
    {
        PII tmp = q.front();
        q.pop();
        int x = tmp.X, y = tmp.Y;
        int t = M[tmp];
        if (t && s != t) addedge(s, t, vis[x][y]);
        for (int i = 0; i < 4; i++)
        {
            int nx = x + tx[i], ny = y + ty[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (maze[nx][ny] == '#') continue;
            if (~vis[nx][ny]) continue;
            vis[nx][ny] = vis[x][y] + 1;
            q.push(mp(nx, ny));
        }
    }
}
int par[maxn << 1];
void init(int n)
{
    for (int i = 0; i <= n; i++) par[i] = i;
}
int find(int x)
{
    return par[x] != x ? par[x] = find(par[x]) : x;
}
int solve(int n)
{
    sort(edges.begin(), edges.end());
    init(n);
    int ret = 0, cnt = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        Edge& e = edges[i];
        int u = e.Y.X, v = e.Y.Y;
        int w = e.X;
        int x = find(u), y = find(v);
        if (x != y)
        {
            ret += w;
            par[y] = x;
            if (++cnt == n - 1) break;
        }
    }
    return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> m >> n;
        char c;
        while ((c = getchar()) == ' ')
            ;
        vector<PII> S;
        for (int i = 0; i < n; i++)
            getline(cin, maze[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (maze[i][j] == 'S' || maze[i][j] == 'A')
                    S.pb(mp(i, j));
        M.clear();
        edges.clear();
        for (int i = 0; i < S.size(); i++)
            M[S[i]] = i + 1;
        for (int i = 0; i < S.size(); i++)
            bfs(S[i], n, m);
        cout << solve(S.size()) << endl;
    }
    return 0;
}
