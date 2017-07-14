#include <bits/stdc++.h>
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

int main()
{
    int n, a, b, sb, t;
    while (cin >> n >> a >> b)
    {
        int cnt = 0;
        sb = 0;
        while (n--)
        {
            cin >> t;
            if (t == 1)
            {
                if (a) a--;
                else if (b) b--, sb++;
                else if (sb) sb--;
                else cnt++;
            }
            else if (t == 2)
            {
                if (b) b --;
                else cnt += 2;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
