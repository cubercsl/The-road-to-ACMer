// Supermarket, POJ1456

/*Sample Input
4  50 2  10 1   20 2   30 1

7  20 1   2 1   10 3  100 2   8 2
   5 20  50 10
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
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

const int maxn = 10005;
PII node[maxn];

bool cmp(PII a, PII b)
{
    return a.Y < b.Y;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> node[i].X >> node[i].Y;
        sort(node, node + n, cmp);
        priority_queue<PII, vector<PII>, greater<PII> > q;
        for (int i = 0; i < n; i++)
        {
            if (node[i].Y > q.size())
                q.push(node[i]);
            else if (node[i].X > q.top().X)
            {
                q.pop();
                q.push(node[i]);
            }
        }
        int ans = 0;
        while (!q.empty())
        {
            ans += q.top().X;
            q.pop();
        }
        cout << ans << endl;
    }
    return 0;
}
