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
    ll f[25];
    char s[25];
    f[0] = 1;
    for (int i = 1; i < 25; i++) f[i] = f[i - 1] * i;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        scanf("%s", s);
        unordered_map<char, int> cnt;
        for (int i = 0; i < n; i++) cnt[s[i]]++;
        int tmp = 0;
        ll ans = f[n / 2];
        for (auto& t : cnt)
        {
            if (t.Y & 1) tmp++;
            ans /= f[t.Y / 2];
        }
        if (tmp > 1)
            puts("0");
        else
            printf("%lld\n", ans);
    }

    return 0;
}
