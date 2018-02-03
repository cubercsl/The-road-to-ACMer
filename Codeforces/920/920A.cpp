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

const int maxn = 205;
int vis[maxn];
int d[] = {-1, 1};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        clr(vis, -1);
        scanf("%d%d", &n, &m);
        queue<int> q;
        while (m--)
        {
            static int c;
            scanf("%d", &c);
            --c;
            vis[c] = 1;
            q.push(c);
        }
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for(int i = 0;  i< 2; i++)
            {
                int y = x + d[i];
                if(y < 0 || y == n || ~vis[y]) continue;
                vis[y] = vis[x] + 1;
                q.push(y);
            }
        }
        printf("%d\n", *max_element(vis, vis + n));
    }
    return 0;
}
