// Doing Homework, HDU1074

/*Sample Input
2
3
Computer 3 3
English 20 1
Math 3 2
3
Computer 3 3
English 6 3
Math 6 3
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

const int maxn = 105;
const int maxm = 1 << 16;
PII node[maxn]; // deadline,time
string s[20];
int n, maxc;
int dp[maxm], pre[maxm], tc[maxm]; // previous,timecomplete

void print(int state)
{
    if (!state)
        return;
    print(state - (1 << pre[state]));
    cout << s[pre[state]] << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> s[i] >> node[i].X >> node[i].Y;
        clr(dp, 0x3f);
        clr(tc, 0x3f);
        dp[0] = 0;
        tc[0] = 0;
        maxc = 1 << n;
        for (int i = 1; i < maxc; i++)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int tmp = 1 << j;
                if (tmp & i)    //  i - tmp is previous state
                {
                    int plt = max(0, node[j].Y + tc[i - tmp] - node[j].X);
                    if (plt + dp[i - tmp] < dp[i])
                    {
                        dp[i] = plt + dp[i - tmp];
                        tc[i] = node[j].Y + tc[i - tmp];
                        pre[i] = j;
                    }
                }
            }
        }
        cout << dp[maxc - 1] << endl;
        print(maxc - 1);
    }
    return 0;
}
