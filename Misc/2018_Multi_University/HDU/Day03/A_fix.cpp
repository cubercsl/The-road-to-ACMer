#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;
int a[N], dq[N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, k, p, q, r, mod;
        scanf("%d%d%d%d%d%d%d", &n, &m, &k, &p, &q, &r, &mod);
        for (int i = 1; i <= k; i++) scanf("%d", a + i);
        for (int i = k + 1; i <= n; i++) a[i] = (1LL * p * a[i - 1] + 1LL * q * i + r) % mod;
        reverse(a + 1, a + n + 1);
        int head = 0, tail = 0;
        long long ans = 0, cnt = 0;
        for (int i = 1, j = 1, k = n - m + 1; i + m - 1 <= n; i++, k--)
        {
            while (j < i + m)
            {
                while (head != tail && a[dq[tail - 1]] <= a[j]) --tail;
                dq[tail++] = j, j++;
            }
            while (dq[head] < i) ++head;
            ans = ans + (a[dq[head]] ^ k);
            cnt = cnt + ((tail - head) ^ k);
        }
        printf("%lld %lld\n", ans, cnt);
    }
}