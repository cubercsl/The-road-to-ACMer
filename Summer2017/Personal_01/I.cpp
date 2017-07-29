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

const int maxn = 1e6 + 5;
int dp[maxn];

int main()
{
    string str;
    while (cin >> str)
    {
        stack <int> s;
        clr(dp, -1);
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '(')
            {
                s.push(i);
            }
            else if (!s.empty())
            {
                dp[i] = s.top();
                dp[s.top()] = i;
                s.pop();
            }
        }
        int cnt = 1;
        int ans = 0;
        int now = 0;
        for (int i = 0; i <= str.length(); i++)
        {
            if (i < str.length() && dp[i] >= 0)
            {
                now++;
                continue;
            }
            else if (ans == now)
                cnt++;
            else if (now > ans)
            {
                ans = now;
                cnt = 1;
            }
            now = 0;
        }
        if (ans == 0)
            cnt = 1;
        cout << ans << " " << cnt << endl;
    }
    return 0;
}
