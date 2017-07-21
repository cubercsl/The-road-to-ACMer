// A Bug's Life, HDU1829

/*Sample Input
2
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

const int maxn = 2000 << 1 + 5;
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
    if (x == y) return;
    par[y] = x;
}

bool same(int x, int y)
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
    int t;
    int kase = 0;
    cin >> t;
    while (t--)
    {
        int n, m;
        bool flag = false;
        cin >> n >> m;
        init(n << 1);
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            if (same(a - 1, b - 1) || same(a - 1 + n, b - 1 + n))
                flag = true;
            else
            {
                unite(a - 1, b - 1 + n);
                unite(a - 1 + n, b - 1);
            }
        }
        cout << "Scenario #" << ++kase << ":" << endl;
        if (flag)
            cout << "Suspicious bugs found!" << endl;
        else
            cout << "No suspicious bugs found!" << endl;
        cout << endl;
    }
    return 0;
}
