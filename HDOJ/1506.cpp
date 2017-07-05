// Largest Rectangle in a Histogram, HDU1506

/*Sample Input
7 2 1 4 5 1 3 3
4 1000 1000 1000 1000
0
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

const int maxn = 1e5 + 5;
int n;
ll a[maxn];

ll solve()
{
    ll ans = -INF;
    int tmp;
    stack<int> s;
    a[n] = -1;
    for (int i = 0; i <= n; i++)
    {
        if (s.empty() || a[i] > a[s.top()])
            s.push(i);
        else if (a[i] < a[s.top()])
        {
            while (!s.empty() && a[s.top()] >= a[i])
            {
                ans = max(ans, (i - s.top()) * a[s.top()]);
                tmp = s.top();
                s.pop();
            }
            s.push(tmp);
            a[tmp] = a[i];
        }
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (~scanf("%d", &n), n)
    {
        for (int i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        printf("%lld\n", solve());
    }
    return 0;
}
