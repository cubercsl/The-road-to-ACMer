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

const int N = 2005;
char s[N][N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    if (k == 1)
    {
        ll ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans += s[i][j] == '.';
        cout << ans << endl;
        return 0;
    }
    vector<ll> v;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '.')
                cnt++;
            else
            {
                if (cnt >= k) v.pb(cnt);
                cnt = 0;
            }
        }
        if (cnt >= k) v.pb(cnt);
    }
    for (int j = 0; j < m; j++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i][j] == '.')
                cnt++;
            else
            {
                if (cnt >= k) v.pb(cnt);
                cnt = 0;
            }
        }
        if (cnt >= k) v.pb(cnt);
    }
    ll ans = 0;
    for (auto t : v) ans += t - k + 1;
    cout << ans << endl;
    return 0;
}
