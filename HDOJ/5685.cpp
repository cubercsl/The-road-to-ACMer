// Problem A, HDU5685

/*Sample Input
2
ACMlove2015
1 11
8 10
1
testMessage
1 1
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
const int mod = 9973;
const double eps = 1e-6;

const int maxn = 1e5 + 5;
int prod[maxn];
int inv[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, a, b;
    char s[maxn];
    inv[1] = 1;
    for (int i = 2; i < mod; i++) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    while (~scanf("%d", &n))
    {
        scanf("%s", s + 1);
        prod[0] = 1;
        for (int i = 1; s[i]; i++)
            prod[i] = prod[i - 1] * (s[i] - 28) % mod;
        while (n--)
        {
            scanf("%d%d", &a, &b);
            int ans = prod[b] * inv[prod[a - 1]] % mod;
            printf("%d\n", ans);
        }
    }
    return 0;
}
