// Ant Trip, HDU3018

/*Sample Input
3 3
1 2
2 3
1 3

4 2
1 2
3 4
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

const int maxn = 1e5 + 5;
vector <int> v;
int par[maxn];
int deg[maxn];
int odd[maxn];
bool vis[maxn];
void init(int n)
{
    v.clear();
    clr(vis, 0);
    clr(deg, 0);
    clr(odd, 0);
    for (int i = 0; i < n; i++)
        par[i] = i;
}

int find(int x)
{
    if (par[x] != x)
        par[x] = find(par[x]);
    return par[x];
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
        par[y] = x;
}

bool same (int x, int y)
{
    return find(x) == find(y);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int n, m;
    while (cin >> n >> m)
    {
        init(n);
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            deg[a - 1]++, deg[b - 1]++;
            unite(a - 1, b - 1);
        }
        for (int i = 0; i < n; i++)
        {
            int tmp = find(i);
            if (!vis[tmp])
            {
                v.pb(tmp);
                vis[tmp] = 1;
            }
            if (deg[i] & 1)
                odd[tmp]++;
        }
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
        {
            int tmp = v[i];
            if (deg[tmp] == 0)
                continue;
            if (odd[tmp] == 0)
                ans++;
            else
                ans += odd[tmp] >> 1;
        }
        cout << ans << endl;
    }
    return 0;
}
