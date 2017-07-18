// How Many Tables, HDU1213

/*Sample Input
2
5 3
1 2
2 3
4 5

5 1
2 5
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

const int maxn = 1005;
int par[maxn];

void init(int n)
{
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
    par[x] = y;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        init(n);
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            unite(a - 1, b - 1);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (par[i] == i)
                ans++;
        cout << ans << endl;
    }
    return 0;
}
