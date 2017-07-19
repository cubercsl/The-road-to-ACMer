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

int main()
{
    int n, m;
    int a[102], b[102];
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        sort(a, a + n);
        sort(b, b + m);
        int ans = max(a[0] * 2, a[n - 1]);
        if (ans < b[0])
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
