#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[15][5], b[15][5];
int main()
{
    for (int i = 0; i < 10; i++)
        scanf("%lld%lld", &a[i][0], &a[i][1]);

    for (int i = 0; i < 10; i++)
        scanf("%lld%lld%lld", &b[i][0], &b[i][1], &b[i][2]);
    ll t = 0;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            if (t >= b[i][2])
            {
                ll tmp1 = (t - b[i][2]) % (b[i][0] + b[i][1]);
                //ll tmp2 = (t - b[i][2] - 1) / (b[i][0] + b[i][1]);
                if (tmp1 >= b[i][0])
                {
                    b[i][2] = max(t + a[i][0], t + b[i][0] + b[i][1] - tmp1);
                    t += a[i][0] + a[i][1];
                }
                else
                {
                    b[i][2] = t + b[i][0] - tmp1 + max(a[i][0], b[i][1]);
                    t += b[i][0] - tmp1 + a[i][0] + a[i][1];
                }
            }
            else
            {
                b[i][2] = max(t + a[i][0], b[i][2]);
                t += a[i][0] + a[i][1];
            }
            //cout << t << " ";
        }
        //cout << endl;
    }
    t -= a[9][1];
    printf("%lld\n", t);
}