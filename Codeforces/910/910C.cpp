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

ll a[26];
bool lead[26];

int main()
{
#ifndef ONLINE_JUDGE
// freopen("1.in", "r", stdin);
// freopen("1.out", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n))
    {
        char s[10];
        clr(lead, 0);
        clr(a, 0);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", s);
            int m = strlen(s);
            int tmp = 1;
            for (int i = m - 1; ~i; i--, tmp *= 10)
                a[s[i] - 'a'] += tmp;
            lead[s[0] - 'a'] = 1;
        }
        pair<ll, int> p[26];
        for (int i = 0; i < 26; i++) p[i] = mp(a[i], i);
        sort(p, p + 26, greater<pair<ll, int>>());
        int cur = 1;
        ll ans = 0;
        bool used = 0;
        for (int i = 0; i < 26; i++)
        {
            if (!used && !lead[p[i].Y]) {
                used = 1;
                continue;
            }
            ans += (ll)p[i].X * (cur++);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
