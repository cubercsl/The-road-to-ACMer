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

const int maxn = 1002;

int main()
{
    Tcase
    {
        int a[maxn];
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        int ans = 0, flag = n;
        while (flag)
        {
            if (flag == 1)
            {
                ans += a[0];
                break;
            }
            else if (flag == 2)
            {
                ans += a[1];
                break;
            }
            else if (flag == 3)
            {
                ans += a[2] + a[0] + a[1];
                break;
            }
            else
            {
                ans += min(a[1] + a[0] + a[flag - 1] + a[1], a[flag - 1] + 2 * a[0] + a[flag - 2]);
                flag -= 2;
            }
        }
        cout << ans << endl;
    }
}
