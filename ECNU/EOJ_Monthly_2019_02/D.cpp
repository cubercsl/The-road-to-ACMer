#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll x, int k, int m)
{
    int pos = 0;
    static int a[100];
    do
    {
        a[pos++] = x % k;
    } while (x /= k);
    reverse(a, a + pos);
    // for (int i = 0; i < pos; i++) printf("%d", a[i]);
    // puts("");
    pos -= m;
    if (pos < 0) return 0;
    ll ans = 0;
    ll ans2 = 0;
    for (int i = 0; i < pos; i++) ans = ans * k + a[i];
    for (int i = 0; i < pos - 1; i++) ans2 = ans2 * k + a[i];
    return ans - ans2;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        static ll l, r;
        static int k, m;
        scanf("%lld%lld%d%d", &l, &r, &k, &m);
        printf("%lld\n", solve(r, k, m) - solve(l - 1, k, m));
    }
}