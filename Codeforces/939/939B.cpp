#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int N = 1 << 17;
ll a[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    ll n;
    int k;
    cin >> n >> k;
    ll ans = -1e18;
    int id = -1;
    for (int i = 1; i <= k; i++) cin >> a[i];
    for (int i = 1; i <= k; i++)
    {
        ll tmp = n / a[i] * a[i];
        if (tmp > ans) ans = tmp, id = i;
    }
    cout << id << " " << n / a[id] << endl;
    return 0;
}