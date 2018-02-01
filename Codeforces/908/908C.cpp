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

int x[1005];
double h[1005];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, r;
    cin >> n >> r;
    h[0] = r;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        h[i] = r;
        double M = 0;
        int pos = -1;
        for (int j = i - 1; ~j; j--)
        {
            if (2 * r >= abs(x[j] - x[i]))
                if (M < x[j]) M = h[j], pos = j;
        }
        if (~pos) h[i] = M + sqrt(4 * r * r - (x[pos] - x[i]) * (x[pos] - x[i]));
        printf("%.10f ", h[i]);
    }
    return 0;
}
