#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define eps 1e-15

const int maxn = 1e6 + 5;
struct seg
{
    double l, r, y;
    int sign;
    seg() {}
    seg(double a, double b, double h, int s) : l(a), r(b), y(h), sign(s) {}
    bool operator<(const seg& cmp) const
    {
        if (cmp.y == y) return sign > cmp.sign;
        return y < cmp.y;
    }
} p[(maxn << 1) + 1];
double sum[(maxn << 2) + 7];
int cnt[(maxn << 2) + 7];
double X[(maxn << 1) + 9];

void push_up(int rt, int l, int r)
{
    if (cnt[rt])
        sum[rt] = X[r + 1] - X[l];
    else if (l == r)
        sum[rt] = 0.0;
    else
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void update(int L, int R, int cc, int l, int r, int rt)
{
    if (L <= l && r <= R) {
        cnt[rt] += cc;
        push_up(rt, l, r); //?
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, cc, lson);
    if (R > m) update(L, R, cc, rson);
    push_up(rt, l, r);
}
int bin(int low, int high, double key)
{
    int mid;
    while (low < high) {
        mid = (low + high) >> 1;
        if (X[mid] < key)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m, k, pp;
    double a, b, c, d, ret;
    while (scanf("%d", &n) != EOF && n) {
        memset(sum, 0, sizeof(sum));
        memset(cnt, 0, sizeof(cnt));
        m = k = 0;
        ret = 0.0;
        pp = 1;

        for (int i = 0; i < n; i++) {
            scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
            X[m++] = a;
            X[m++] = c;
            p[k++] = seg(a, c, b, 1);
            p[k++] = seg(a, c, d, -1);
        }
        sort(X, X + m);
        sort(p, p + k);
        for (int i = 1; i < m; i++)
            if (X[i - 1] != X[i]) {
                X[pp++] = X[i];
            }
        pp--;
        for (int i = 0; i < k - 1; i++) {
            int l = bin(0, pp, p[i].l);
            int r = bin(0, pp, p[i].r) - 1;
            if (l <= r) update(l, r, p[i].sign, 0, pp, 1);
            ret += (p[i + 1].y - p[i].y) * sum[1];
        }
        printf("%d\n", (int)ret);
    }
    puts("*");
    return 0;
}
