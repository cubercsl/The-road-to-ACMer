// Black Box, POJ1442

/*Sample Input
7 4
3 1 -4 2 8 -1000 2
1 2 6 6
*/

#include <iostream>
#include <vector>
#include <queue>
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

const int maxn = 30005;
int a[maxn];

int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        for (int i = 0; i < m; i++)
            cin >> a[i];
        priority_queue<int> p1;
        priority_queue<int, vector<int>, greater<int> > p2;
        int now = 0;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            while (now < t)
            {
                int x = a[now];
                if (!p1.empty())
                {
                    if (x > p1.top())
                        p2.push(x);
                    else
                    {
                        p2.push(p1.top());
                        p1.pop();
                        p1.push(x);
                    }
                }
                else p2.push(x);
                now++;
            }
            cout << p2.top() << endl;
            p1.push(p2.top());
            p2.pop();
        }
    }

    return 0;
}
