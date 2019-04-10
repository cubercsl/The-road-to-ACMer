#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;
typedef long long ll;
ll num[N], sum[N];
const int mod = 1e9 + 7;
inline void update(int x, ll v, ll* bit)
{
    for (; x < N; x += x & -x) bit[x] += v;
}
inline ll query(int x, ll* bit)
{
    ll t = 0;
    for (; x; x -= x & -x) t += bit[x];
    return t;
}
vector<int> prime;
bool isprime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return n != 1;
}
void init(int n)
{
    int tot = 0;
    for (int i = 2; i <= n; i++)
        if (isprime(i)) prime.push_back(i);
}
ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}
void update(int l, int r, ll x)
{
    update(l, x, num);
    update(r + 1, -x, num);
    update(l, 1LL * (l - 1) * x, sum);
    update(r + 1, 1LL * (-r) * x, sum);
}
ll query(int l, int r)
{
    return (1LL * r * query(r, num) - query(r, sum)) - (1LL * (l - 1) * query(l - 1, num) - query(l - 1, sum));
}

int a[N];
int l[N], r[N], x[N];
ll ans[N];
int main()
{
    init(300);
    int n, q;
    scanf("%d%d", &n, &q);
    int M = prime.size();
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < q; i++)
    {
        static char op[10];
        scanf("%s%d%d", op, &l[i], &r[i]);
        if (op[0] == 'T')
            x[i] = -1;
        else
            scanf("%d", &x[i]);
        ans[i] = 1;
    }
    for (int t = 0; t < M; t++)
    {
        memset(num, 0, sizeof(num));
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i++)
        {
            int cnt = 0;
            while (a[i] % prime[t] == 0)
            {
                cnt++;
                a[i] /= prime[t];
            }
            if (cnt) update(i, i, cnt);
        }
        for (int i = 0; i < q; i++)
        {
            if (~x[i])
            {
                int cnt = 0;
                while (x[i] % prime[t] == 0)
                {
                    cnt++;
                    x[i] /= prime[t];
                }
                if (cnt) update(l[i], r[i], cnt);
            }
            else
            {
                ll cnt = query(l[i], r[i]);
                if (cnt)
                {
                    ans[i] = ans[i] * Pow(prime[t], cnt - 1) % mod;
                    ans[i] = ans[i] * (prime[t] - 1) % mod;
                }
            }
        }
    }
    for (int i = 0; i < q; i++)
        if (!~x[i]) printf("%lld\n", ans[i]);
}