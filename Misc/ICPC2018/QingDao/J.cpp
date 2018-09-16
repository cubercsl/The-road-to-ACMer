#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int T;
    ll a, b, c, d, v, t;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &v, &t);
        ll g = __gcd(a, c);
        ll lcm = a * c / g;
        vector<ll> vec;
        for (ll i = 0, j = 0; i != lcm || j != lcm;)
        {
            if (i < j)
                i += a;
            else
                j += c;
            vec.push_back(min(i, j));
        }
        sort(vec.begin(), vec.end());
        ll tmp = 0;
        for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i] - vec[i - 1] > v)
                tmp++;
        }
        ll ans = b * (t / a) + d * (t / c) + b + d - 1;
        ll cnt = t / lcm;
        cnt *= tmp;
        ans -= cnt;
        t %= lcm;
        for (int i = 1; vec[i] <= t; i++)
        {
            if (vec[i] - vec[i - 1] > v)
                ans--;
        }
        printf("%lld\n", ans);
    }
}
