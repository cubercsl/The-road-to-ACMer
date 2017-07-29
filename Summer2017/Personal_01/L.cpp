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

const int maxn = 2e5 + 5;
ll dp[maxn];

int main()
{
    string s;
    while (cin >> s)
    {
        dp[0] = s[0] - '0';
        for (int i = 1; i < s.length(); i++)
            dp[i] = (dp[i - 1] * 10 + (i + 1) * (s[i] - '0')) % mod;
        ll ans = 0;
        for (int i = 0; i < s.length(); i++)
            ans = (ans + dp[i]) % mod;
        cout << ans << endl;
    }
    return 0;
}
