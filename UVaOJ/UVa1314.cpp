// Hidden Password, UVa1314

/*Sample Input
2
6 baabaa
7 alabala
*/

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
char s[maxn];
int solve(int n)
{
    int i, j, l;
    i = 0;
    j = 1;
    while (i < n && j < n)
    {
        for (l = 0; l < n; l++)
            if (s[(i + l) % n] != s[(j + l) % n]) break;
        if (l == n) break;
        if (s[(i + l) % n] > s[(j + l) % n])
            i = i + l + 1;
        else
            j = j + l + 1;
        if (i == j) j = i + 1;
    }
    return min(i, j);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d%s", &n, s);
        printf("%d\n", solve(n));
    }
    return 0;
}
