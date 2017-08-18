// xiaoxin juju needs help, HDU5651

/*Sample Input
3
aa
aabb
a
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
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 1005;
int M[300];
ll fact[maxn];
ll inv[maxn];

ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, a = (a * a % mod))
        if (n & 1) t = (t * a % mod);
    return t;
}

void init()
{
    fact[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = Pow(fact[i], mod - 2);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    init();
    int t;
    char s[maxn];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s);
        clr(M, 0);
        for (int i = 0; i < strlen(s); i++)
            M[s[i]]++;
        int cnt = 0;
        for (int i = 0; i < 300; i++)
        {
            if (M[i] & 1)
                cnt++;
            M[i] >>= 1;
        }
        if (cnt > 1)
        {
            printf("0\n");
            continue;
        }
        ll ans = fact[strlen(s) / 2];
        for (int i = 0; i < 300; i++)
        {
            if (M[i])
                ans = ans * inv[M[i]] % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
