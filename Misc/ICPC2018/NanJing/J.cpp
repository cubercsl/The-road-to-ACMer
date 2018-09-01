#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
const int maxn = 2e7 + 5;
int prime[maxn], tot;
ll tt[maxn];
bool check[maxn];
void caltt()
{
    tt[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!check[i])
            prime[tot++] = i, tt[i] = 2;
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] >= maxn)
                break;
            //if (prime[j] < 272 && i >= prime[j] * prime[j] * prime[j] && i % (prime[j] * prime[j] * prime[j]) == 0)
            //    tt[i] = 0;

            check[i * prime[j]] = true;
            if (1LL * i % (prime[j] * prime[j]) == 0)
                tt[i * prime[j]] = 0;
            else if (i % prime[j] == 0)
            {
                tt[i * prime[j]] = tt[i / prime[j]];
                break;
            }
            else
                tt[i * prime[j]] = 2 * tt[i];
        }
    }
    for (int i = 2; i < maxn; i++)
        tt[i] += tt[i - 1];
}
int main()
{
    caltt();
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        printf("%lld\n", tt[n]);
    }
    return 0;
}