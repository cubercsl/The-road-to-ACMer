#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
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

const int maxn = 200005;
int dp[maxn];
int _dp[maxn];
int cnt[105];
int v[105];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, t;
    int maxv = 0;
    cin >> n >> t;
    clr(dp, 0x3f);
    clr(_dp, 0x3f);
    dp[0] = 0, _dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        maxv = max(maxv, v[i]);
    }
    int maxt = t + maxv * maxv;
    for (int i = 0; i < n; i++)
        cin >> cnt[i];
    for (int i = 0; i < n; i++)
        for (int j = v[i]; j <= maxt; j++)
            _dp[j] = min(_dp[j - v[i]] + 1, _dp[j]);
    for (int i = 0; i < n; i++)
    {
        int num = cnt[i];
        for (int k = 1; num > 0; k <<= 1)
        {
            int mul = min(k, num);
            for (int j = maxt; j >= v[i]*mul; j--)
                dp[j] = min(dp[j - v[i] * mul] + mul, dp[j]);
            num -= mul;
        }
    }
    int ans = INF;
    for (int i = t; i <= maxt; i++)
        ans = min(dp[i] + _dp[i - t], ans);
    if (ans < INF)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}

