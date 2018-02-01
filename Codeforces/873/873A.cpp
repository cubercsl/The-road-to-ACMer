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
    freopen("1.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
    int n, k, x;
    while (cin >> n >> k >> x)
    {
        int sum = 0;
        int num;
        for (int i = 0; i < n - k; i++)
        {
            cin >> num;
            sum += num;
        }
        for (int i = n - k; i < n; i++)
        {
            cin >> num;
            sum += min(num, x);
        }
        cout << sum << endl;
    }
    return 0;
}
