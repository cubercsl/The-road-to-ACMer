// 小希的迷宫, HDU1272

/*Sample Input
6 8  5 3  5 2  6 4
5 6  0 0

8 1  7 3  6 2  8 9  7 5
7 4  7 8  7 6  0 0

3 8  6 8  6 4
5 3  5 6  5 2  0 0

-1 -1
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
    for (int i = 0; i < maxn; i++)
        par[i] = i;
}

int find(int x)
{
    if (par[x] != x)
        par[x] = find(par[x]);
    return par[x];
}

bool unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return false;
    par[y] = x;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int a, b, n;
    bool flag;
    bool vis[maxn];
    while (cin >> a >> b, a >= 0 && b >= 0)
    {
        clr(vis, 0);
        flag = true;
        n = max(a, b);
        if (a > 0)
        {
            init();
            vis[a - 1] = vis[b - 1] = true;
            flag &= unite(a - 1, b - 1);
            while (cin >> a >> b, a + b)
            {
                flag &= unite(a - 1, b - 1);
                vis[a - 1] = vis[b - 1] = true;
                n = max(max(a, b), n);
            }
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (vis[i] && find(i) == i)
                    cnt++;
                if (cnt > 1)
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
