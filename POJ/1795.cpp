// DNA Laboratory, POJ1795

/*Sample Input
1
2
TGCACA
CAT
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
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

string str[16];
int n;
int dp[1 << 16][16];
int cost[16][16];
string ans;

void print(int cur, int s)
{
    if (s == 0) return;
    string mmin;
    int nxt = -1;
    for (int i = 0; i < n; i++)
    {
        if (i == cur) continue;
        if (!(s >> i & 1)) continue;
        if (dp[s][cur] != dp[s - (1 << cur)][i] + cost[cur][i]) continue;
        string tmp = str[i].substr(str[cur].length() - cost[cur][i]);
        if (nxt == -1 || tmp < mmin)
            nxt = i, mmin = tmp;
    }
    ans += mmin;
    print(nxt, s - (1 << cur));
}

int solve()
{
    for (int i = 0; i < n; i++)
        dp[1 << i][i] = str[i].length();
    for (int s = 0; s < (1 << n); s++)
        for (int j = 0; j < n; j++)
            if (dp[s][j] != INF && (s >> j & 1))
                for (int i = 0; i < n; i++)
                    if (!((s >> i) & 1))
                        dp[s | 1 << i][i] = min(dp[s | 1 << i][i], dp[s][j] + cost[i][j]);
    int ret = 0;
    for (int i = 1; i < n; i++)
        if (dp[(1 << n) - 1][i] < dp[(1 << n) - 1][ret])
            ret = i;
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    cin >> T;
    int kase = 0;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> str[i];
        cout << "Scenario #" << ++kase << ":" << endl;
        if (n == 1)
        {
            cout << str[0] << endl
                 << endl;
            continue;
        }
        clr(dp, 0x3f);
        clr(cost, 0);
        //去重
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j && str[i].find(str[j]) != string::npos)
                    str[j] = str[i];
        sort(str, str + n);
        n = unique(str, str + n) - str;
        if (n == 1)
        {
            cout << str[0] << endl
                 << endl;
            continue;
        }
        //去重后计算花费
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    int len = min(str[i].length(), str[j].length());
                    for (int k = 0; k <= len; k++)
                        if (str[i].substr(str[i].length() - k) == str[j].substr(0, k))
                            cost[i][j] = str[i].length() - k;
                }
            }
        int id = solve();
        ans = str[id];
        print(id, (1 << n) - 1);
        cout << ans << endl
             << endl;
    }
    return 0;
}
