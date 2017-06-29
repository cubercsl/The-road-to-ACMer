// Throwing cards away I, UVa10935

/*Sample Input
7
19
10
6
0
*/

#include <bits/stdc++.h>
#define input(n) while(cin >> n)
#define input_2(a, b) while(cin >> a >> b)
#define Tcase int T; cin >> T; while(T--)
#define clr(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x & -x)
#define Lson L, mid, node << 1
#define Rson mid + 1, R, node << 1 | 1
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (cin >> n, n)
    {
        queue<int> q;
        int flag = 0;
        while (!q.empty())
            q.pop();
        for (int i = 1; i <= n; i++)
            q.push(i);
        cout << "Discarded cards:";
        while (q.size() > 1)
        {
            if (flag++)
                cout << ",";
            cout << " " << q.front();
            q.pop();
            q.push(q.front());
            q.pop();
        }
        cout << endl;
        cout << "Remaining card: " << q.front() << endl;
    }
    return 0;
}
