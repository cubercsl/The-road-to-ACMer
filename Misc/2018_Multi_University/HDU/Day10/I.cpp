#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e7 + 5;
bool vis[maxn];
int tot, phi[maxn], prime[maxn];
long long ans[maxn];
void CalPhi(int n)
{
    memset(vis, 0, sizeof(vis));
    phi[1] = 1;
    tot = 0;
    for (int i = 2; i < n; i++)
    {
        if (!vis[i])
            prime[tot++] = i, phi[i] = i - 1;
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] > n) break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (i & 1)
            ans[i] = ans[i - 1] + phi[i] / 2;
        else
            ans[i] = ans[i - 1] + phi[i];
    }
}

int main()
{
    CalPhi(2e7 + 2);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        printf("%lld\n", ans[n]);
    }
}
