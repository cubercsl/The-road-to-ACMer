// Wireless Network, POJ2236

/*Sample Input
4 1
0 1
0 2
0 3
0 4
O 1
O 2
O 4
S 1 4
O 3
S 1 4
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
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
struct Node
{
    int x, y;
    bool repair;
} Comp[maxn];
int par[maxn], rnk[maxn];
int n, d;

void init (int n)
{
    for (int i = 1; i <= n; i++)
        par[i] = i, rnk[i] = 0;
}

int find (int x)
{
    if (par[x] != x)
        par[x] = find(par[x]);
    return par[x];
}

void unite (int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (rnk[x] < rnk[y])
        par[x] = y;
    else
    {
        par[y] = x;
        if (rnk[x] == rnk[y])
            rnk[x]++;
    }
}

bool same (int x, int y)
{
    return find(x) == find(y);
}

double dis(Node a, Node b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> Comp[i].x >> Comp[i].y;
    init(n);
    char cmd[2];
    while (cin >> cmd)
    {
        if (cmd[0] == 'O')
        {
            int num;
            cin >> num;
            Comp[num].repair = 1;
            for (int i = 1; i <= n; i++)
                if (Comp[i].repair && dis(Comp[i], Comp[num]) <= d * 1.0)
                    unite(i, num);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            if (same(x, y))
                cout << "SUCCESS" << endl;
            else
                cout << "FAIL" << endl;
        }
    }
    return 0;
}
