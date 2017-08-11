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


const int maxn = 2005;
struct node
{
    int a, b;
    bool operator < (const node &rhs) const
    {
        return a + b < rhs.a + rhs.b;
    }
} x[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int n, h;
    int dp[maxn];
    while (cin >> n)
    {
        int k = 0;
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i].a >> x[i].b;
            dp[i] = -1, dp[0] += x[i].a;
        }
        cin >> h;
        sort(x + 1, x + 1 + n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = k; j >= 0; j--)
                if (dp[j] + x[i].b >= h)
                    dp[j + 1] = max(dp[j + 1], dp[j] - x[i].a);
            if (dp[k + 1] != -1) k++;
        }
        cout << k << endl;
    }
    return 0;
}
