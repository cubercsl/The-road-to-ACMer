// X-Plosives, UVa1160

/*Sample Input
1 2
3 4
3 5
3 1
2 3
4 1
2 6
6 5
-1
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
int par[maxn];

void init()
{
    for (int i = 1; i <= 100000; i++)
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
        par[x] = y;
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
    int x, y;
    while (cin >> x)
    {
        init();
        int cnt = 0;
        while (x != -1)
        {
            cin >> y;
            if (same(x, y))
                cnt++;
            else
                unite(x, y);
            cin >> x;
        }
        cout << cnt << endl;

    }
    return 0;
}
