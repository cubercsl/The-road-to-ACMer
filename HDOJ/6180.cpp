// Schedule, 2017 Multi-University Training Contest, HDU6180

/*Sample Input
1
3
1 3
4 6
2 5
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
PII a[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &a[i].X, &a[i].Y);
        sort(a, a + n);
        int cnt = 0;
        ll sum = 0;
        priority_queue<int> p;                                 //free
        priority_queue<int, vector<int>, greater<int> > q;     //work
        for (int i = 0; i < n; i++)
        {
            while (!q.empty() && q.top() <= a[i].X)
            {
                p.push(q.top());
                q.pop();
            }
            if (!p.empty())
            {
                int tmp = p.top();
                p.pop();
                sum += a[i].Y - tmp;
                q.push(a[i].Y);
            }
            else
            {
                cnt++;
                sum += a[i].Y - a[i].X;
                q.push(a[i].Y);
            }
        }
        printf("%d %lld\n", cnt, sum);
    }
    return 0;
}
