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

const int N = 1 << 17;
int a[N];
ll sum[N];
bool check(int n)
{
    if (sum[n] & 1)
        return false;
    for (int i = 1; i <= n; i++)
        if (binary_search(sum + i + 1, sum + n + 1, sum[n] / 2 + a[i]))
            return true;
    for (int i = n; i; i--)
        if (binary_search(sum + 1, sum + i, sum[n] / 2 - a[i]))
            return true;
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++) scanf("%d", &a[i + 1]);
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + a[i + 1];
        puts(check(n) ? "YES" : "NO");
    }
    return 0;
}
