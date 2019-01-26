// ybmj
#include <bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define lson_len (len - (len >> 1))
#define rson_len (len >> 1)
#define pb(x) push_back(x)
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define my_unique(a) a.resize(distance(a.begin(), unique(a.begin(), a.end())))
#define my_sort_unique(c) (sort(c.begin(), c.end())), my_unique(c)
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const double PI = acos(-1.0);
const int maxn = 1e7 + 5;
int n, m, sr, sc, er, ec;
int dr[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dc[] = {-2, -1, 1, 2, 2, 1, -1, -2};
bool vis[maxn][2];
struct Node
{
    int r, c, cnt;
};

int id(int x, int y)
{
    return (x - 1) * m + y;
}
bool bfs()
{
    queue<Node> Q;
    Q.push({sr, sc, 0});
    while (!Q.empty())
    {
        Node now = Q.front();
        Q.pop();
        if (now.r == er && now.c == ec)
        {
            if (now.cnt & 1) return true;
            continue;
        }
        for (int i = 0; i < 8; i++)
        {
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];
            if (nr >= 1 && nr <= n && nc >= 1 && nc <= m && !vis[id(nr, nc)][(now.cnt + 1) & 1])
            {
                vis[id(nr, nc)][(now.cnt + 1) & 1] = 1;
                Q.push({nr, nc, now.cnt + 1});
            }
        }
    }
    return false;
}
int main()
{
//	/*
#ifndef ONLINE_JUDGE
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    //	*/
    std::ios::sync_with_stdio(false);
    scanf("%d%d%d%d%d%d", &n, &m, &sr, &sc, &er, &ec);
    if ((sr + sc) % 2 != (er + ec) % 2)
    {
        puts("No");
        return 0;
    }
    if (n <= 10 || m <= 10)
    {
        if (bfs())
            puts("Yes");
        else
            puts("No");
    }
    else
        puts("Yes");
}