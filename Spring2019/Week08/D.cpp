#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll a, ll d, ll m, ll n)
{
    if (n == 0) return 0;
    if (n == 1) return a / m;
    ll tmp = (a / m) * n + (n - 1) * n / 2 * (d / m);
    a %= m, d %= m;
    if (d == 0) return tmp;
    return tmp + solve((a + d * n) % m, m, d, (a + d * n) / m);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int p, q, n;
        scanf("%d%d%d", &p, &q, &n);
        // ll bf = 0;
        // for (int i = 1; i <= n; i++) bf += p * i % q;
        ll ans = 1LL * p * n * (n + 1) / 2 - solve(p, p, q, n) * q;
        // printf("%lld\n", bf);
        printf("%lld\n", ans);
        // assert(bf == ans);
    }
}