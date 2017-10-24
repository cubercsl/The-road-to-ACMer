#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (cin >> n >> m)
    {
        int tmp;
        queue<int> p, q;
        while (n--)
        {
            cin >> tmp;
            p.push(tmp);
        }
        while (m--)
        {
            cin >> tmp;
            q.push(tmp);
        }
        bool flag = 0;
        while (!p.empty() && !q.empty())
        {
            int a = p.front(), b = q.front();
            if (a == 30 || b == 30)
                p.pop(), q.pop();
            else if (a == 32 && b == 31)
                q.pop();
            else if (a == 31 && b == 32)
                p.pop();
            else if (a == 31 && b == 31)
            {
                flag = 1;
                break;
            }
            else if (a == 31)
                q.pop();
            else if (b == 31)
                p.pop();
            else if (a == b)
                p.pop(), q.pop();
            else if (a > b)
                q.pop();
            else
                p.pop();
        }
        if (flag || p.empty() && q.empty())
            cout << "Draw" << endl;
        else if (q.empty())
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    }
    return 0;
}
