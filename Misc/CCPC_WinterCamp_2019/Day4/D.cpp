#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n, m;
    scanf("%lld%lld", &n, &m);
    //n--, m--;
    if (n > m) swap(n, m);
    ll s = n * (m - 1) + m * (n - 1);
    ll ans=0;
    if (n == 1)
    {
        ans = 2 * m + m + 1 + ((m - 1) / 2) * 2;
        m -= 1;
        if (m & 1) ans += 1;
    }
    else if (n == 2)
    {
        if (m % 2 == 0)
            ans = 3 * m + 2 * (m + 1) + 4 + ((m - 2) / 2) * 2;
        else
            ans = 3 * m + 2 * (m + 1) + 4 + (2 * m - 4) / 2;
        ans = 4 * (m - 1);
    }
    else
    {
        /*ans = 2 * n * m + n + m;
        if ((n % 2 == 1) && (m % 2 == 1))
            ans += ((n - 1) / 2) * 2 + ((m - 1) / 2) * 2;
        else if ((n % 2 == 0) && (m % 2 == 0))
            ans += ((n - 1) / 2) * 2 + ((m - 1) / 2) * 2 + 4;
        if (n % 2 == 1)
        {
            ans += ((m - 2) / 2) * 2 + (n - 1) / 2 + (n - 3) / 2 + 4;
        }
        else
        {
            ans += ((n - 2) / 2) * 2 + (m - 1) / 2 + (m - 3) / 2 + 4;
        }*/
        ans = s;
        n -= 2;
        m -= 2;
        if (n % 2 == 0 && m % 2 == 0)
            ans += n + m;
        else
            ans += n + m + 2;
    }
    printf("%lld\n", ans);
}