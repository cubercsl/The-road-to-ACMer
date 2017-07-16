// Coin Change, UVa674

/*Sample Input
11
26
*/

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

const int maxn = 7500;
int dp[maxn];
int c[] = {1, 5, 10, 25, 50};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    dp[0] = 1;
    for (int i = 0; i < 5; i++)
        for (int j = c[i]; j < maxn; j++)
            dp[j] += dp[j - c[i]];
    int n;
    while (cin >> n)
        cout << dp[n] << endl;
    return 0;
}
