// 非常可乐, HDU1495

/*Sample Input
7 4 3
4 1 3
0 0 0
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

const int maxn = 105;
int vis[maxn][maxn];

struct node
{
    int s, n, m;
    node (int _s, int _n, int _m)
    {
        s = _s, n = _n, m = _m;
    }
};

bool check(int s, int n, int m)
{
    if (n == m && s == 0)
        return true;
    if (s == n && m == 0)
        return true;
    if (s == m && n == 0)
        return true;
    return false;
}

int bfs(int s, int n, int m)
{
    clr(vis, -1);
    vis[0][0] = 0;
    queue<node> q;
    q.push(node(s, 0, 0));
    while (!q.empty())
    {
        node tmp = q.front();
        q.pop();
        int S = tmp.s;
        int N = tmp.n;
        int M = tmp.m;
        // cout << S << " " << N << " " << M << endl;
        if (check(S, N, M)) return vis[N][M];
        int ts[] = {max(S + N - n, 0), min(S + N, s), max(S + M - m, 0), min(S + M, s), S, S};
        int tn[] = {min(N + S, n), max(N + S - s, 0), N, N, max(N + M - m, 0), min(N + M, n)};
        int tm[] = {M, M, min(M + S, m), max(M + S - s, 0), min(M + N, m), max(M + N - n, 0)};
        for (int i = 0; i < 6; i++)
        {
            if (vis[tn[i]][tm[i]] == -1)
            {
                vis[tn[i]][tm[i]] = vis[N][M] + 1;
                q.push(node(ts[i], tn[i], tm[i]));
            }
        }
    }
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int s, n, m;
    while (cin >> s >> n >> m, s + n + m)
    {
        if (s % 2)
            cout << "NO" << endl;
        else
        {
            int ans = bfs(s, n, m);
            if (ans > 0)
                cout << ans << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
