// Co-prime, HDU4135

/*Sample Input
2
1 10 2
3 15 5
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

const int maxn = 1e6 + 5;
ll fact[maxn];
int cnt;
int getFactors(ll n)
{
    int cnt = 0;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0) fact[++cnt] = i;
        while (n % i == 0) n /= i;
    }
    if (n != 1) fact[++cnt] = n;
    return cnt;
}

ll dfs(int now, ll n)
{
    ll ans = 0;
    for (int i = now; i <= cnt; i++)
        ans += n / fact[i] - dfs(i + 1, n / fact[i]);
    return ans;
}

int main()
{
    fastin
    int t;
    int kase = 0;
    cin >> t;
    while (t--)
    {
        ll a, b, n;
        cin >> a >> b >> n;
        cnt = getFactors(n);
        ll ans = b - dfs(1, b) - (a - 1 - dfs(1, a - 1));
        cout << "Case #" << ++kase << ": ";
        cout << ans << endl;
    }
    return 0;
}
