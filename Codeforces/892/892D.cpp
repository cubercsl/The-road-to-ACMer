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
    PII a[25];
    int b[25];
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++) scanf("%d", &a[i].X), a[i].Y = i;
        sort(a, a + n);
        for (int i = 0; i < n; i++) b[a[i].Y] = a[(i + 1) % n].X;
        for (int i = 0; i < n; i++) printf("%d%c", b[i], i == n - 1 ? '\n' : ' ');
    }
    return 0;
}