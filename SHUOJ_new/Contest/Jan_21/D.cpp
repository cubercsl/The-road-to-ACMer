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

int vis[100000][4][3];
typedef pair<int, PII> Node;

inline VI split(int x)
{
    VI v;
    for (int i = 0; i < 5; i++, x /= 10) v.pb(x % 10);
    reverse(v.begin(), v.end());
    return v;
}

inline VI Op1(int x)
{
    VI v = split(x), ret;
    for (int i = 1; i < 5; i++)
    {
        swap(v[i - 1], v[i]);
        int num = 0;
        for (auto d : v) (num *= 10) += d;
        ret.pb(num);
        swap(v[i - 1], v[i]);
    }
    return ret;
}

inline VI Op2(int x)
{
    VI v = split(x), ret;
    for (auto& t : v)
    {
        int tmp = t;
        (++t) %= 10;
        int num = 0;
        for (auto d : v) (num *= 10) += d;
        ret.pb(num);
        t = tmp;
    }
    return ret;
}

inline VI Op3(int x)
{
    VI v = split(x), ret;
    for (auto& t : v)
    {
        int tmp = t;
        (t <<= 1) %= 10;
        int num = 0;
        for (auto d : v) (num *= 10) += d;
        ret.pb(num);
        t = tmp;
    }
    return ret;
}

inline void bfs()
{
    clr(vis, -1);
    queue<Node> q;
    vis[12345][3][2] = 0;
    q.push(mp(12345, mp(3, 2)));
    while (!q.empty())
    {
        Node tmp = q.front();
        q.pop();
        int cur = tmp.X;
        // printf("%d\n", cur);
        int x = tmp.Y.X, y = tmp.Y.Y;
        // op1
        VI op1 = Op1(cur);
        for (auto num : op1)
        {
            if (~vis[num][x][y]) continue;
            vis[num][x][y] = vis[cur][x][y] + 1;
            q.push(mp(num, mp(x, y)));
        }
        // op2
        if (x)
        {
            VI op2 = Op2(cur);
            for (auto num : op2)
            {
                if (~vis[num][x - 1][y]) continue;
                vis[num][x - 1][y] = vis[cur][x][y] + 1;
                q.push(mp(num, mp(x - 1, y)));
            }
        }
        // op3
        if (y)
        {
            VI op3 = Op3(cur);
            for (auto num : op3)
            {
                if (~vis[num][x][y - 1]) continue;
                vis[num][x][y - 1] = vis[cur][x][y] + 1;
                q.push(mp(num, mp(x, y - 1)));
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    bfs();
    int n;
    while (~scanf("%d", &n))
    {
        int ans = INF;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 3; j++)
                if (~vis[n][i][j])
                    ans = min(ans, vis[n][i][j]);
        printf("%d\n", ans != INF ? ans : -1);
    }
    return 0;
}
