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
    int a[55];
    while (cin >> n >> m)
    {
        for (int i = 0; i < m; i++)
            cin >> a[i];
        sort(a, a + m);
        int ans = INF;
        for (int i = n - 1; i < m; i++)
            ans = min(ans, a[i] - a[i - n + 1]);
        cout << ans << endl;
    }
    return 0;
}
