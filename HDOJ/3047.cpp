// Zjnu Stadium, HDU3047 

/*Sample Input
10 10
1 2 150
3 4 200
1 5 270
2 6 200
6 5 80
4 7 150
8 9 100
4 8 50
1 7 100
9 2 100

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

const int maxn = 50005;
int par[maxn], rnk[maxn];

void init(int n)
{
    for (int i = 1; i <= n; i++)
        par[i] = i, rnk[i] = 0;
}

int find(int x)
{
    if (par[x] == x)return x;
    int t = find(par[x]);
    rnk[x] += rnk[par[x]];
    return par[x] = t;
}

bool unite(int x, int y, int d)
{
    int t1 = find(x);
    int t2 = find(y);
    if (t1 == t2)
    {
        if (rnk[x] + d != rnk[y])
            return false;
        return true;
    }
    par[t2] = t1;
    rnk[t2] = rnk[x] + d - rnk[y];
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int n, m;
    while (cin >> n >> m)
    {
        init(n);
        int cnt = 0;
        while (m--)
        {
            int a, b, d;
            cin >> a >> b >> d;
            if (!unite(a, b, d))
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
