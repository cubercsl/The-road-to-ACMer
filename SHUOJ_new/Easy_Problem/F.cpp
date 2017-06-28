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

const int maxn = 102;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    input_2(n, m)
    {
        queue<PII> q;
        for (int i = 1; i <= n; i++)
        {
            int num;
            cin >> num;
            q.push(mp(num, i));
        }
        int now = 1;
        while (q.size() > 1)
        {
            PII tmp = q.front();
            q.pop();
            if (now++ == m)
                now = 1, m = tmp.first;
            else
                q.push(tmp);
        }
        PII tmp = q.front();
        q.pop();
        cout << tmp.second << endl;
    }
    return 0;
}
