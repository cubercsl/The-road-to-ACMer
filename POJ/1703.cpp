// Find them, Catch them, POJ1703

/*Sample Input
1
5 5
A 1 2
D 1 2
A 1 2
D 2 4
A 1 4
*/

#include <iostream>
#include <cstdio>
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

const int maxn = 3e5 + 7;
int par[maxn];

void init(int n)
{
    for (int i = 1; i <= n; i++)
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
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, q;
        scanf("%d%d", &n, &q);
        init(2 * n);
        while (q--)
        {
            char cmd;
            int a, b;
            scanf("\n%c%d%d", &cmd, &a, &b);
            if (cmd == 'A')
            {
                if (same(a, b) || same(a + n, b + n))
                    printf("In the same gang.\n");
                else if (same(a, b + n) || same(a + n, b))
                    printf("In different gangs.\n");
                else
                    printf("Not sure yet.\n");
            }
            else
            {
                unite(a, b + n);
                unite(b, a + n);
            }
        }
    }
    return 0;
}
