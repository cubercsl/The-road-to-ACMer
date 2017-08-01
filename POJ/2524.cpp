// Ubiquitous Religions, POJ2524

/*Sample Input
10 9
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
10 4
2 3
4 5
4 8
5 8
0 0
*/

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

const int maxn = 50005;
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
    if (x == y)return;
    par[y] = x;
}

int main()
{
    fastin
    int n, m, kase = 0;
    while (cin >> n >> m, m + n)
    {
        init(n);
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            unite(a, b);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (find(i) == i)
                cnt++;
        cout << "Case " << ++kase << ": " << cnt << endl;
    }
    return 0;
}
