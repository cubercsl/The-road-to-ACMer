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
/*
void dfs(int i, const int& n, int& ans, int cur)
{
    if (i == n + 1)
    {
        ans = min(ans, abs(cur));
        return;
    }
    dfs(i + 1, n, ans, cur + i * i);
    dfs(i + 1, n, ans, cur - i * i);
}
*/
int a[] = {0, 1, 3, 4, 2, 3, 1, 0, 0};
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
        if (n <= 8)
            printf("%d\n", a[n]);
        else
            printf("%d\n", (n + 1) >> 1 & 1);
    }
    return 0;
}