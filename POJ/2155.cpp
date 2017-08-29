// Matrix, POJ2155

/*Sample Input
1
2 10
C 2 1 2 2
Q 2 2
C 2 1 2 1
Q 1 1
C 1 1 2 1
C 1 2 1 2
C 1 1 2 2
Q 1 1
C 1 1 2 1
Q 2 1
*/

#include <iostream>
#include <vector>
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

const int maxn = 1005;
int BIT[maxn][maxn], n;

inline int lowbit (int x)
{
    return x & (-x);
}

void add(int x, int y, int val)
{
    while (x <= n)
    {
        int t = y;
        while (t <= n)
        {
            BIT[x][t] ^= val;
            t += lowbit(t);
        }
        x += lowbit(x);
    }
}

bool query(int x, int y)
{
    bool ans = 0;
    while (x)
    {
        int t = y;
        while (t)
        {
            ans ^= BIT[x][t];
            t -= lowbit(t);
        }
        x -= lowbit(x);
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int t, q;
    char c[2];
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        clr(BIT, 0);
        while (q--)
        {
            cin >> c;
            if (c[0] == 'C')
            {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                add(x1, y1, 1);
                add(x1, y2 + 1, 1);
                add(x2 + 1, y1, 1);
                add(x2 + 1, y2 + 1, 1);
            }
            else
            {
                int x, y;
                cin >> x >> y;
                cout << query(x, y) << endl;
            }
        }
        if (t) cout << endl;
    }
    return 0;
}
