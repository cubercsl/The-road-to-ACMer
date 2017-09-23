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

PII a[105];
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        int ans = -1;
        for (int i = 0; i < m; i++)
        {
            cin >> a[i].X >> a[i].Y;
            a[i].X--, a[i].Y--;
        }
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        n--;
        for (int i = 1; i <= 100; i++)
        {
            // cout << "i = " << i << endl;
            bool flag = 0;
            for (int j = 0; j < m; j++)
            {
                int k = a[j].X / i;
                // cout << k << " " << a[j].Y << endl;
                if (k != a[j].Y)
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)
            {
                int tmp = n / i + 1;
                if (ans == -1)
                    ans = tmp;
                else if (ans != tmp)
                {
                    ans = -1;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
