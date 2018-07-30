#include <bits/stdc++.h>
using namespace std;
struct query
{
    int l, r, id;
};
int main()
{
    int n, q;
    while (~scanf("%d%d", &n, &q))
    {
        int m = n << 1 | 1;
        vector<int> a(m), bit(m);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) a[n + i] = a[i];
        vector<query> v(q);
        vector<int> last(n + 1, -1), ans(q);
        for (int i = 0; i < q; i++) scanf("%d%d", &v[i].r, &v[i].l), v[i].id = i, v[i].r += n;
        sort(v.begin(), v.end(), [](const query& a, const query& b) { return a.r < b.r; });
        for (int i = 0, j = 1; i < q; i++)
        {
            for (; j <= v[i].r; j++)
            {
                if (~last[a[j]])
                    for (int k = last[a[j]]; k < m; k += k & -k) bit[k]--;
                for (int k = j; k < m; k += k & -k) bit[k]++;
                last[a[j]] = j;
            }
            int t = 0;
            for (int k = m; k; k -= k & -k) t += bit[k];
            for (int k = v[i].l - 1; k; k -= k & -k) t -= bit[k];
            ans[v[i].id] = t;
        }
        for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
    }
    return 0;
}