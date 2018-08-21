#include <bits/stdc++.h>
using namespace std;

const int p = 1e9 + 7;
const int M = 1 << 7;
const int N = 1 << 17;
int bit[M][N];
int inv[M];

void update(int* bit, int x, int y)
{
    for (int i = x; i < N; i += i & -i)
        if ((bit[i] += y) >= p) bit[i] -= p;
}

int query(int* bit, int x)
{
    int ret = 0;
    for (int i = x; i; i -= i & -i)
        if ((ret += bit[i]) >= p) ret -= p;
    return ret;
}

int main()
{
    inv[1] = 1;
    for (int i = 2; i < M; i++) inv[i] = 1LL * inv[p % i] * (p - p / i) % p;
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    --k;
    while (m--)
    {
        static int op, x, y;
        scanf("%d", &op);
        if (op == 0)
        {
            scanf("%d%d", &x, &y);
            long long u = 1;
            for (int i = 0; i <= k; i++)
            {
                update(bit[i], x, y * u % p);
                u = u * (k - x - i) % p * inv[i + 1] % p;
                if (u < 0) u += p;
            }
        }
        else
        {
            scanf("%d", &x);
            long long u = 1, ans = 0;
            for (int i = 0; i <= k; i++)
            {
                ans = (ans + u * query(bit[k - i], x)) % p;
                u = u * (x - i) % p * inv[i + 1] % p;
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}