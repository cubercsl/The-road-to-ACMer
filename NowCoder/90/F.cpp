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
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll n, sum = 1, cnt;
        scanf("%lld", &n);
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                cnt = 0;
                while (n % i == 0) n /= i, cnt++;
                sum *= 2 * cnt + 1;
            }
        }
        if (n != 1) sum *= 3;
        printf("%lld\n", (sum + 1) >> 1);
    }
    return 0;
}
