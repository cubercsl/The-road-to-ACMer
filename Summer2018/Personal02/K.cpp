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

const int maxn = 1 << 20;
int n, x, prime[maxn], tot, mu[maxn];
bool check[maxn];
void calmu()
{
    mu[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!check[i]) prime[tot++] = i, mu[i] = -1;
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] >= maxn) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            else
                mu[i * prime[j]] = -mu[i];
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    calmu();
    int T;
    int kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int a, b, c, d, k;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        printf("Case %d: ", ++kase);
        if (k == 0)
        {
            puts("0");
            continue;
        }
        if (b > d) swap(b, d);
        b /= k, d /= k;
        ll aa = 0, bb = 0;
        for (int i = 1; i <= b; i++) aa += 1LL * mu[i] * (b / i) * (d / i);
        for (int i = 1; i <= b; i++) bb += 1LL * mu[i] * (b / i) * (b / i);
        printf("%lld\n", aa - bb / 2);
    }
    return 0;
}
