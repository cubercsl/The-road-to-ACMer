// Balanced Lineup, POJ3264

/*Sample Input
6 3
1
7
3
4
2
5
1 5
4 6
2 2
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

const int maxn =  50000 + 5;
int mmax[maxn][30], mmin[maxn][30];
int a[maxn], n, k, q;

void init()
{
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        mmax[i][0] = mmin[i][0] = a[i];
    }
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            mmax[i][j] = max(mmax[i][j - 1], mmax[i + (1 << (j - 1))][j - 1]);
            mmin[i][j] = min(mmin[i][j - 1], mmin[i + (1 << (j - 1))][j - 1]);
        }
}

int rmq(int l, int r)
{
    int k = 0;
    while ((1 << (k + 1)) <= r - l + 1) k++;
    return max(mmax[l][k], mmax[r - (1 << k) + 1][k]) - min(mmin[l][k], mmin[r - (1 << k) + 1][k]);
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d%d", &n, &q);
    init();
    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", rmq(l, r));
    }
    return 0;
}
