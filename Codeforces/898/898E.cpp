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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, x;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > q1, q2;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        int tmp = sqrt(x);
        if (tmp * tmp == x)
            q1.push(tmp ? 1 : 2);
        else
            q2.push(min((tmp + 1) * (tmp + 1) - x, x - tmp * tmp));
    }
    ll ans = 0;
    while (q1.size() > n / 2) ans += q1.top(), q1.pop();
    while (q2.size() > n / 2) ans += q2.top(), q2.pop();
    cout << ans << endl;
    return 0;
}
