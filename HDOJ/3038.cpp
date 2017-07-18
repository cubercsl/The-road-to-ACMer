// How Many Answers Are Wrong, HDU3038

/*Sample Input
10 5
1 10 100
7 10 28
1 3 32
4 6 41
6 6 1
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

const int maxn = 2e5 + 5;
int par[maxn], val[maxn];

void init(int n)
{
    for (int i = 0; i <= n; i++)
        par[i] = i, val[i] = 0;
}

int find(int x)
{
    if (par[x] == x)
        return x;
    int tmp = find(par[x]);
    val[x] += val[par[x]];
    return par[x] = tmp;
}

void unite(int x, int y, int s)
{
    int t1 = find(x);
    int t2 = find(y);
    if (t1 == t2) return;
    par[t2] = t1;
    val[t2] = val[x] - val[y] + s;
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
    int n, m;
    while (cin >> n >> m)
    {
        init(n);
        int l, r, s, cnt = 0;
        while (m--)
        {
            cin >> l >> r >> s;
            l--;
            if (!same(l, r))
                unite(l, r, s);
            else if (val[r] - val[l] != s)
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
