#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    ll k;
    scanf("%d%lld", &n, &k);
    ll old = 0, ans = 0, tmp;
    for (int i = 0; i < n; i++)
    {
        ll ta;
        scanf("%lld", &tmp);
        if(old)
            ta = max((old + k - 1) / k, (tmp + old) / k);
        else
            ta = tmp / k;
        old = max(1LL * 0, old + tmp - ta * k);
        ans += ta;
    }
    if (old) ans++;
    printf("%lld\n", ans);
}