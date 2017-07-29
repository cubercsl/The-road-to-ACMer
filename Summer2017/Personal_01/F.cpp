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
struct node
{
    ll hp, g, c;
    bool operator < (const node &b) const
    {
        return g * b.c > c * b.g;
    }
} ma[maxn];

int main()
{
#ifndef ONLINE_JUDGE
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif
    fastin
    int t;
    int kase = 0;
    cin >> t;
    while (t--)
    {
        int n, m;
        ll tot = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> ma[i].hp >> ma[i].g;
            ma[i].c = (ma[i].hp + m - 1) / m;
            tot += ma[i].g;
        }
        sort(ma, ma + n);
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ll cnt =ma[i].c;
            ans += cnt * tot;
            tot -= ma[i].g;
        }
        cout << "Case #" << ++kase << ": " << ans << endl;
    }
    return 0;
}
