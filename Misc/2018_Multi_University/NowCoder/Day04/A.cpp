#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

unordered_map<int, int> phi;
const int mod = 1e9 + 7;

inline ll Phi(ll n)
{
    if (phi[n]) return phi[n];
    ll num = n;
    int ans = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans -= ans / i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) ans -= ans / n;
    return phi[num] = ans;
}

ll Pow(ll a, ll n, ll p)
{
    ll t = 1;
    assert(n >= 0);
    for (; n; n >>= 1, (a *= a) %= p)
        if (n & 1) (t *= a) %= p;
    return t;
}

const int N = 1 << 17;
char s[N];
int a[N], c[N];

int main()
{
    for (int p = mod; p != 1; p = phi[p]) phi[p] = Phi(p);
    phi[1] = 1;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        int n = strlen(s);
        for (int i = 0; i < n; i++) a[i] = s[i] - '0';
        c[n - 1] = mod;
        for (int i = n - 1; i; i--)
        {
            if (a[i] == 2)
                c[i - 1] = phi[c[i]];
            else
                c[i - 1] = c[i];
            assert(c[i - 1]);
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0) ans = (ans + 1) % c[i];
            if (a[i] == 1) ans = (ans * 2 + 2) % c[i];
            if (a[i] == 2) ans = (((Pow(2, ans, c[i]) * 6LL % c[i] - 3LL) % c[i]) + c[i]) % c[i];
        }
        printf("%lld\n", ans);
    }
}