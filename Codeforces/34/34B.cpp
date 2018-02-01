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

const int maxn = 102;
int main()
{
    int n, m;
    int a[maxn];
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            if (a[i] > 0)
                break;
            ans += a[i];
        }
        cout << -ans << endl;
    }
    return 0;
}
