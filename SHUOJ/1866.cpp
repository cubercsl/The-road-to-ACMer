#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    bool vis[105][105];
    int n, m, x, y;
    while(~scanf("%d%d%d%d", &n, &m, &x, &y))
    {
        int cnt = 1;
        int tx[] = {x, y, -x, -y, x, y, -x, -y};
        int ty[] = {y, x, y, x, -y, -x, -y, -x};
        clr(vis, 0);
        vis[0][0] = 1;
        queue<PII> q;
        q.push(mp(0, 0));
        while(!q.empty())
        {
            PII tmp  = q.front();
            q.pop();
            int xx = tmp.X, yy= tmp.Y;
            for(int i = 0; i < 8; i++)
            {
                int nx = xx + tx[i], ny = yy + ty[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m ||vis[nx][ny]) continue;
                vis[nx][ny]  = 1;
                cnt++;
                q.push(mp(nx, ny));
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
