#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1 << 20;
const int mod = 119 << 23 | 1;
bool vis[N];
ll prime[N], tot;
ll d[N], t[N];
void init()
{
    tot = 0;
    for (int i = 2; i < N; i++)
    {
        if (!vis[i])
            prime[tot++] = i;
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] >= N)
                break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
ll solve(ll l, ll r, ll k)
{
    ll ans = 0;
    for (ll i = l; i <= r; i++)
        d[i - l] = 1,  t[i - l] = i;
    for (int i = 0; i < tot; i++)
    {
        ll tmp = prime[i];
        if (tmp < l)
            tmp = prime[i] * ((l + prime[i] - 1) / prime[i]);
        for (; tmp <= r; tmp += prime[i])
        {
            ll cnt = 0;
            while (t[tmp - l] % prime[i] == 0)
                t[tmp - l] /= prime[i], cnt++;
            if (cnt != 0)
                d[tmp - l] = (d[tmp - l] * (k * cnt % mod + 1) % mod) % mod;
        }
    }
    for (ll i = l; i <= r; i++)
        if (d[i - l] == 1)
            ans = (ans + k + 1) % mod;
        else if (t[i - l] != 1)
            ans = (ans + d[i - l] * (k + 1)) % mod;
        else
            ans = (ans + d[i - l]) % mod;
    return ans;
}

int main()
{
    init();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll l, r;
        ll k;
        scanf("%lld%lld%lld", &l, &r, &k);
        ll ans = solve(l, r, k);
        if (l == 1) ans = ans - k;
        ans = (ans + mod) % mod;
        printf("%lld\n", ans);
    }
}