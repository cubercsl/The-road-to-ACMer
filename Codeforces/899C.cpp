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
    int n;
    while (~scanf("%d", &n))
    {
        if(n % 4 == 0)
        {
            puts("0");
            printf("%d", n / 2);
            for (int i = 0; i < n / 2; i += 2) printf(" %d %d", i + 1, n - i);
            puts("");
        }
        else if(n % 4 == 1)
        {
            puts("1");
            printf("%d 1", (n - 1) / 2 + 1);
            for (int i = 0; i < (n - 1) / 2; i += 2) printf(" %d %d", i + 2, n - i);
            puts("");
        }
        else if(n % 4 == 2)
        {
            puts("1");
            printf("%d 1", (n - 2) / 2 + 1);
            for (int i = 0; i < (n - 2) / 2; i += 2) printf(" %d %d", i + 3, n - i);
            puts("");
        }
        else
        {
            puts("0");
            printf("%d 1 2", (n - 3) / 2 + 2);
            for (int i = 0; i < (n - 3) / 2; i += 2) printf(" %d %d", i + 4, n - i);
            puts("");
        }
    }
    return 0;
}
