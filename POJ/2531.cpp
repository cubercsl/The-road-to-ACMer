// Network Saboteur, POJ2531

/*Sample Input
3
0 50 30
50 0 40
30 40 0
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

int n, ans, m[25][25];
int a[25], b[25];
void calc(int an, int bn)
{
    int sum = 0;
    for (int i = 0; i < an; i++)
        for (int j = 0; j < bn; j++)
            sum += m[a[i]][b[j]];
    ans = max(ans, sum);
}

void dfs(int dep, int an, int bn)
{
    if (dep == n)
    {
        calc(an, bn);
        return;
    }
    a[an] = dep;
    dfs(dep + 1, an + 1, bn);
    b[bn] = dep;
    dfs(dep + 1, an, bn + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> m[i][j];
        ans = -INF;
        dfs(0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}
