#include <iostream>
#include <cstring>
#include <vector>
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

const int maxn = 505;
const int maxe = 10005;
int from[maxe], to[maxe], w[maxe];
int dis[maxn], tot;

void add_edge(int u, int v, int d)
{
    from[tot] = u;
    to[tot] = v;
    w[tot++] = d;
}

bool bellman(int s, int n)
{
    clr(dis, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < tot; j++)
        {
            int x = from[j], y = to[j];
            if (dis[y] > dis[x] + w[j])
            {
                dis[y] = dis[x] + w[j];
                if (i == n - 1)return true;
            }
        }
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int f, n, m, w;
    cin >> f;
    while (f--)
    {
        tot = 0;
        cin >> n >> m >> w;
        while (m--)
        {
            int u, v, d;
            cin >> u >> v >> d;
            add_edge(u, v, d);
            add_edge(v, u, d);
        }
        while (w--)
        {
            int u, v, d;
            cin >> u >> v >> d;
            add_edge(u, v, -d);
        }
        if (bellman(1, n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

