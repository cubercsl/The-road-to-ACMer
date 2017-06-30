#include <bits/stdc++.h>
#define input(n) while(cin >> n)
#define input_2(a, b) while(cin >> a >> b)
#define Tcase int T; cin >> T; while(T--)
#define clr(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x & -x)
#define Lson L, mid, node << 1
#define Rson mid + 1, R, node << 1 | 1
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 1e5 + 5;
int n, k;
int vis[maxn];

int bfs()
{
    queue <int> q;
    clr(vis, -1);
    while (!q.empty())
        q.pop();
    vis[n] = 0;
    q.push(n);
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        int nxt[3] = {tmp + 1, tmp - 1, tmp * 2};
        for (int i = 0; i < 3; i++)
        {
            if (nxt[i] < 0 || nxt[i] > maxn)
                continue;
            if (vis[nxt[i]] == -1)
            {
                vis[nxt[i]] = vis[tmp] + 1;
                q.push(nxt[i]);
            }
            if (nxt[i] == k)
                return vis[k];
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
    input_2(n, k)
    cout << bfs() << endl;
    return 0;
}
