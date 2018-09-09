//moira
#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
typedef long long ll;
const int maxn = 1e6 + 5;
int prime[maxn], tot, mu[maxn], Mu[maxn];
bool check[maxn];
map<ll, ll> M;
map<ll, ll> T;
void calmu()
{
    mu[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!check[i])
            prime[tot++] = i, mu[i] = -1;
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
    for (int i = 1; i < maxn; i++)
        Mu[i] = Mu[i - 1] + mu[i];
}
ll work(ll x)
{
    if (x < maxn) return Mu[x];
    if (M[x]) return M[x];
    ll ans = 1;
    for (ll i = 2, last; i <= x; i = last + 1)
    {
        last = x / (x / i);
        ans -= (last - i + 1) * work(x / i);
    }
    return M[x] = ans;
}
inline int fm(ll n)
{
    if (n < maxn) return mu[n];
    if (T.find(n) != T.end()) return T[n];
    int cnt = 0;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % (i * i) == 0) return 0;
        if (n % i == 0) cnt++, n /= i;
    }
    if (n) cnt++;
    return T[n] = (cnt & 1 ? -1 : 1);
}
ll f(ll m, ll n)
{
    int tmp = fm(n);
    if (m == 1) return tmp == 0 ? 0 : 1;
    if (m == 0 || tmp == 0) return 0;
    if (n == 1) return work(m);
    ll ans = 0;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans += f(m / i, i);
            if (i * i != n)
                ans += f(m / (n / i), n / i);
        }
    }
    return ans;
}
int main()
{
    calmu();
    ll m, n;
    while (~scanf("%lld%lld", &m, &n))
        printf("%lld\n", f(m, n) * fm(n));
    return 0;
}
