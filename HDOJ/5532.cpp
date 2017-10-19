// Almost Sorted Array, HDU5532

/*Sample Input
3
3
2 1 7
3
3 2 1
5
3 1 4 1 5*/

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

const int maxn = 1 << 17;
int a[maxn];
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
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", a + i);

        int _ = 0, __ = 0, ___ = 0, ____ = 0;
        int Max = 0, Min = INF;
        for (int i = 0; i < n && _ < 2; i++)
            if (Max <= a[i])
                Max = a[i];
            else
                _++;
        for (int i = 0; i < n && __ < 2; i++)
            if (Min >= a[i])
                Min = a[i];
            else
                __++;
        Max = 0, Min = INF;
        for (int i = n - 1; ~i && ___ < 2; i--)
            if (Max <= a[i])
                Max = a[i];
            else
                ___++;
        for (int i = n - 1; ~i && ____ < 2; i--)
            if (Min >= a[i])
                Min = a[i];
            else
                ____++;
        puts(_ + __ + ___ + ____ == 8 ? "NO" : "YES");
    }
    return 0;
}
