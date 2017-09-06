#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
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
const double eps = 1e-6;

const int maxn = 13000;
int dp[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m, v, w;
    cin >> n >> m;
    while (n--)
    {
        cin >> v >> w;
        for (int i = m; i >= v; i--)
            dp[i] = max(dp[i], dp[i - v] + w);
    }
    cout << dp[m] << endl;
    return 0;
}
