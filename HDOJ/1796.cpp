// How many integers can you find, HDU1796

/*Sample Input
12 2
2 3
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

const int maxn = 15;
int n, m, t;
ll a[maxn];
ll ans;


ll lcm (ll a, ll b)
{
    return a / __gcd(a, b) * b;
}

void dfs(int id, ll x, int dep)
{
    x = lcm(a[id], x);
    if (dep & 1) ans += (n - 1) / x;
    else ans -= (n - 1) / x;
    for (int i = id + 1; i < t; i++)
        dfs(i, x, dep + 1);
}

int main()
{
    fastin
    while (cin >> n >> m)
    {
        ans = 0;
        t = 0;
        for (int i = 0; i < m; i++)
        {
            ll num;
            cin >> num;
            if (num)
                a[t++] = num;
        }
        for (int i = 0; i < t; i++)
            dfs(i, a[i], 1);
        cout << ans << endl;
    }
    return 0;
}
