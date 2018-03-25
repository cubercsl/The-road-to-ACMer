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

bool isp(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return n != 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int n, ans;
        cin >> n;
        if (isp(n))
            ans = 1;
        else if (n % 2 == 0 || isp(n - 2))
            ans = 2;
        else
            ans = 3;
        cout << ans << endl;
    }
    return 0;
}
