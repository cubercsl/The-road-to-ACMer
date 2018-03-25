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
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        --k;
        vector<int> v(n);
        for (auto& t : v) scanf("%d", &t);
        sort(v.begin(), v.end());
        ll ans = 0;
        for (int i = 0; i + k < n; i++) ans += v[i + k] - v[i];
        printf("Case #%d: %lld\n", ++kase, ans);
    }
    return 0;
}
