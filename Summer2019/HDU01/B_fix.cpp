#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int d[26][100010];
char buf[100010];

int id[26];
bool vis[26];
long long hexi[maxn];
void init()
{
    hexi[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        hexi[i] = hexi[i - 1] * 26 % mod;
    }
}
int main()
{
    int n;
    int kase = 1;
    init();
    while (~scanf("%d", &n))
    {
        int maxm = 0;
        for (int i = 0; i < 26; i++) id[i] = i, vis[i] = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%s", buf);
            int m = strlen(buf);
            if (maxm < m) maxm = m;
            for (int i = m - 1, j = 0; ~i; i--, j++) d[buf[i] - 'a'][j]++;
            if (m > 1)
                vis[buf[0] - 'a'] = true;
        }
        for (int c = 0; c < 26; c++)
        {
            for (int i = 0; i < maxm; i++)
            {
                d[c][i + 1] += d[c][i] / 26;
                d[c][i] %= 26;
            }
        }
        sort(id, id + 26, [&](int a, int b) {
            for (int i = maxm; ~i; i--)
            {
                if (d[a][i] == d[b][i]) continue;
                return d[a][i] < d[b][i];
            }
            return false;
        });
        long long sum = 0;
        bool used = 0;
        int cur = 1;
        for (int i = 0; i < 26; i++)
        {
            if (!used && vis[id[i]] == 0)
            {
                used = 1;
                continue;
            }
            for (int j = 0; j <= maxm; j++)
            {
                sum = (sum + hexi[j] * d[id[i]][j] % mod * cur % mod) % mod;
            }
            cur++;
        }
        printf("Case #%d: %lld\n", kase++, sum);
        for (int i = 0; i < 26; i++)
            for (int j = 0; j <= maxm; j++) d[i][j] = 0;
    }
}