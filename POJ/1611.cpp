// The Suspects, POJ1161

/*Sample Input
100 4
2 1 2
5 10 13 11 12 14
2 0 1
2 99 2
200 2
1 5
5 1 2 3 4 5
1 0
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

const int maxn = 30000 + 5;
int par[maxn], cnt[maxn];
void init (int n)
{
    for (int i = 0; i < n; i++)
        par[i] = i, cnt[i] = 1;
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
    if (x == y) return;
    par[y] = x;
    cnt[x] += cnt[y];
}

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    fastin
    int n, m;
    while (cin >> n >> m, n + m)
    {
        init(n);
        while (m--)
        {
            int k, s, t;
            cin >> k >> s;
            for (int i = 1; i < k; i++)
            {
                cin >> t;
                unite(s, t);
            }
        }
        cout << cnt[find(0)] << endl;
    }
    return 0;
}
