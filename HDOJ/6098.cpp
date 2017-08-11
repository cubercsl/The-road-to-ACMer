// Inversion, 2017 Multi-University Training Contest, HDU6098

/*Sample Input
2
4
1 2 3 4
4
1 4 2 3
*/

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

const int maxn = 1e5 + 5;
PII a[maxn];
int b[maxn];
bool cmp(PII a, PII b)
{
    return a > b;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].X;
            a[i].Y = i + 1;
        }
        sort(a, a + n, cmp);
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < n; j++)
                if (a[j].Y % i != 0)
                {
                    b[i] = a[j].X;
                    break;
                }
        }
        for (int i = 2; i <= n; i++)
        {
            if (i != 2) cout << " ";
            cout << b[i];
        }
        cout << endl;
    }
    return 0;
}
