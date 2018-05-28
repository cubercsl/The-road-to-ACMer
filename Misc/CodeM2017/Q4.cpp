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
typedef pair <int, int> PII;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 1e5 + 5;
int n;
int a[maxn], b[maxn];
bool vis[maxn];
bool vis2[maxn];
char ans[maxn];
vector <int> G[maxn];
queue <int> q;

void bfs()
{
    while (!q.empty())
        q.pop();
    vis[n - 1] = 1;
    q.push(n - 1);
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        for (int i = 0; i < G[tmp].size(); i++)
            if (!vis[G[tmp][i]])
            {
                vis[G[tmp][i]] = 1;
                q.push(G[tmp][i]);
            }
    }
}

void init()
{
    clr(ans, 0);
    clr(vis, 0);
    clr(vis2, 0);
    clr(G, 0);
}

int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    input(n)
    {
        init();
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            int tmp = i + a[i];
            if (tmp >= 0 && tmp < n)
                G[tmp].pb(i);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            int tmp = i + b[i];
            if (tmp >= 0 && tmp < n)
                G[tmp].pb(i);
        }
        bfs();
        if (!vis[0])
        {
            cout << "No solution!" << endl;
            continue;
        }
        int loc = 0;
        int id = 0;
        bool inf = 0;
        while (loc != n - 1)
        {
            if (vis2[loc])
            {
                inf = 1;
                break;
            }
            vis2[loc] = 1;
            int ca = loc + a[loc];
            int cb = loc + b[loc];
            if (ca >= 0 && ca < n && vis[ca])
                ans[id++] = 'a', loc = ca;
            else
                ans[id++] = 'b', loc = cb;
        }
        if (inf)
            cout << "Infinity!" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
