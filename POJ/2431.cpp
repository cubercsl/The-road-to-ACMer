// Expedition, POJ2431

/*Sample Input
4
4 4
5 2
11 5
15 10
25 10
*/

#include <iostream>
#include <queue>
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

const int maxn = 10005;
int l, p, n;
PII a[maxn];

int main()
{
    fastin
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].X >> a[i].Y;
    cin >> l >> p;
    for (int i = 0; i < n; i++)
        a[i].X = l - a[i].X;
    a[n].X = l, a[n++].Y = 0;
    sort(a, a + n);
    priority_queue<int> q;
    int ans = 0, pos = 0, tank = p;
    for (int i = 0; i < n; i++)
    {
        int d = a[i].X - pos;
        while (tank - d < 0)
        {
            if (q.empty())
            {
                cout << -1 << endl;
                return 0;
            }
            tank += q.top();
            q.pop();
            ans++;
        }
        tank -= d;
        pos = a[i].X;
        q.push(a[i].Y);
    }
    cout << ans << endl;
    return 0;
}
