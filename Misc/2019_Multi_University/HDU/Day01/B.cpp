#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int p[maxn][31], pos[maxn][31];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, q;
        scanf("%d%d", &n, &q);
        for (int i = 1, x; i <= n; i++)
        {
            for (int j = 0; j < 31; j++) p[i][j] = p[i - 1][j], pos[i][j] = pos[i - 1][j];
            scanf("%d", &x);
            int ti = i;
            for (int j = 30; ~j; j--)
            {
                if (x & (1 << j))
                {
                    if (!p[i][j])
                    {
                        p[i][j] = x;
                        pos[i][j] = ti;
                        break;
                    }
                    if (pos[i][j] < ti) swap(p[i][j], x), swap(pos[i][j], ti);
                    x ^= p[i][j];
                }
            }
        }
        int op;
        int lastans = 0, l, r;
        while (q--)
        {
            scanf("%d", &op);
            if (op == 0)
            {
                scanf("%d%d", &l, &r);
                l ^= lastans;
                l %= n;
                l++;
                r ^= lastans;
                r %= n;
                r++;
                if (l > r) swap(l, r);
                int res = 0;
                for (int j = 30; ~j; j--)
                    if (pos[r][j] >= l && (res ^ p[r][j]) > res) res ^= p[r][j];
                printf("%d\n", res);
                lastans = res;
            }
            else
            {
                int x;
                scanf("%d", &x);
                x ^= lastans;
                int i = ++n;
                for (int j = 0; j < 31; j++) p[i][j] = p[i - 1][j], pos[i][j] = pos[i - 1][j];
                int ti = i;
                for (int j = 30; ~j; j--)
                {
                    if (x & (1 << j))
                    {
                        if (!p[i][j])
                        {
                            p[i][j] = x;
                            pos[i][j] = ti;
                            break;
                        }
                        if (pos[i][j] < ti) swap(p[i][j], x), swap(pos[i][j], ti);
                        x ^= p[i][j];
                    }
                }
            }
        }
    }
    return 0;
}