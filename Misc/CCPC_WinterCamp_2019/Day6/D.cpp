#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5], b[5], d[5], ans[5];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        for (int i = 0; i < 3; i++) scanf("%lld%lld", a + i, b + i);
        for (int i = 0; i < 3; i++) d[i] = 4 * b[i] - a[i] * a[i];
        int flag = true;
        for (int i = 0; i < 3 && flag; i++)
            for (int j = i + 1; j < 3 && flag; j++)
            {
                ll tmp = d[j] - d[i];
                if (tmp == 0)
                {
                    ll ta = -a[i] - a[j], tb = -a[i] + a[j];
                    if (ta % 2 == 0 && tb % 2 == 0)
                    {
                        ta /= 2, tb /= 2;
                        if ((ta + tb) % 2 == 0)
                            ans[i] = (ta + tb) / 2, ans[j] = (ta - tb) / 2, flag = false;
                    }
                    continue;
                }
                else
                {
                    ll tmp2 = abs(tmp);
                    ll d1 = a[i] + a[j], d2 = a[i] - a[j];
                    for (ll k = 1; k * k <= tmp2 && flag; k++)
                    {
                        if (tmp2 % k) continue;
                        ll ta = k, tb = tmp / k;
                        if ((ta - d1) % 2 == 0 && (tb - d2) % 2 == 0)
                        {
                            ll tc = (ta - d1) / 2, td = (tb - d2) / 2;
                            if ((tc + td) % 2 == 0)
                                ans[i] = (tc + td) / 2, ans[j] = (tc - td) / 2, flag = false;
                        }
                        else if ((tb - d1) % 2 == 0 && (ta - d2) % 2 == 0)
                        {
                            ll tc = (tb - d1) / 2, td = (ta - d2) / 2;
                            if ((tc + td) % 2 == 0)
                                ans[i] = (tc + td) / 2, ans[j] = (tc - td) / 2, flag = false;
                        }
                        else
                        {
                            ta = -k, tb = -tmp / k;
                            if ((ta - d1) % 2 == 0 && (tb - d2) % 2 == 0)
                            {
                                ll tc = (ta - d1) / 2, td = (tb - d2) / 2;
                                if ((tc + td) % 2 == 0)
                                    ans[i] = (tc + td) / 2, ans[j] = (tc - td) / 2, flag = false;
                            }
                            else if ((tb - d1) % 2 == 0 && (ta - d2) % 2 == 0)
                            {
                                ll tc = (tb - d1) / 2, td = (ta - d2) / 2;
                                if ((tc + td) % 2 == 0)
                                    ans[i] = (tc + td) / 2, ans[j] = (tc - td) / 2, flag = false;
                            }
                        }
                    }
                }
            }
        printf("%lld %lld %lld\n", ans[0], ans[1], ans[2]);
    }
    return 0;
}
