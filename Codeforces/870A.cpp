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
    cin >> n >> m;

    int a[10], b[10];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                cout << a[i] << endl;
                return 0;
            }
        }
    if (a[0] > b[0])
        cout << b[0] << a[0] << endl;
    else
        cout << a[0] << b[0] << endl;

    return 0;
}
