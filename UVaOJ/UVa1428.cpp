// Ping Pong, Uva1428

/*Sample Input
1
3 1 2 3
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

const int maxn = 1e5 + 5;
int val[maxn << 1];
int BIT[maxn];
ll lb[maxn << 1], ls[maxn << 1];
int n;

int lowbit(int x)
{
    return x & (-x);
}

void add(int i)
{
    while (i < maxn)
        BIT[i] ++, i += lowbit(i);
}

int query(int i)
{
    int ans = 0;
    while (i > 0)
        ans += BIT[i], i -= lowbit(i);
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int t;
    cin >> t;
    while (t--)
    {
        clr(BIT, 0);
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> val[i];
            ls[i] = query(val[i] - 1);
            lb[i] = i - ls[i];
            add(val[i]);
        }
        ll ans = 0LL;
        for (int i = 0; i < n; i++)
        {
            int rs = query(val[i] - 1) - ls[i];
            int rb = n - i - 1 - rs;
            // cout << ls[i] << " " << lb[i] << " " << rs << " " << rb << endl;
            ans += 1LL * lb[i] * rs + 1LL * ls[i] * rb;
        }
        cout << ans << endl;
    }
    return 0;
}
