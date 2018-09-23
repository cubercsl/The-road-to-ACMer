#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
bool check[maxn];
int prime[maxn], phi[maxn], tot;
void getprime()
{
    phi[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!check[i]) prime[tot++] = i, phi[i] = i - 1;
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] >= maxn) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}
char s[maxn];
int vis[maxn];
int len;
bool chec(int k)
{
    for (int i = 0; i < k; i++)
        if (s[i] == 'R')
            vis[i] = 1;
        else
            vis[i] = 0;
    for (int i = k; i < len; i++)
        if (s[i] == 'P')
            vis[i] = 0;
        else
            vis[i] = vis[i - k];
    for (int i = 1; i <= k; i++)
        if (vis[len - i] == 1)
            return true;
    return false;
}
int main()
{
    getprime();
    while (~scanf("%s", s))
    {
        len = strlen(s);
        if (chec(1))
        {
            printf("%d\n", len - 1);
            continue;
        }
        int ans = 0;
        for (int i = 2; i * i <= len; i++)
        {
            if (len % i == 0)
            {
                if (chec(i))
                    ans += phi[len / i];
                if (i * i != len && chec(len / i))
                    ans += phi[i];
            }
        }
        printf("%d\n", ans);
    }
}
