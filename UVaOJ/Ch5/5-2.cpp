// Ducci Sequence, ACM/ICPC Seoul 2009, UVa1954

/*Sample Input
4
4
8 11 2 7
5
4 2 0 2 0
7
0 0 0 0 0 0 0
6
1 2 3 1 2 3
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

const int maxn = 15;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    Tcase
    {
        int n;
        cin >> n;
        queue <int> q;
        while (!q.empty())
            q.pop();
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            q.push(num);
        }
        bool flag;
        int dep = 1000;
        while (!q.empty() && (dep--))
        {
            flag = 0;
            int a[maxn];
            a[0] = q.front();
            if (a[0])
                flag = 1;
            q.pop();
            for (int i = 1; i < n; i++)
            {
                a[i] = q.front();
                if (a[i])
                    flag = 1;
                q.pop();
                int tmp = abs(a[i] - a[i - 1]);
                q.push(tmp);
            }
            int tmp = abs(a[0] - a[n - 1]);
            q.push(tmp);
            if (!flag)
                break;
        }
        if (flag)
            cout << "LOOP" << endl;
        else
            cout << "ZERO" << endl;
    }
    return 0;
}
