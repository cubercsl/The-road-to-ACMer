// ybmj
#include <bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define lson_len (len - (len >> 1))
#define rson_len (len >> 1)
#define pb(x) push_back(x)
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const int maxn = 1e5+5;
int a[maxn], BIT[maxn];
int lazy[maxn << 2], seg[maxn << 2];
int n, q;

inline int lowb(int x) { return x & (-x); }
inline int query(int l, int r) {
    int ret = 0;
    for (int i = l - 1; i > 0; i -= lowb(i)) ret -= BIT[i];
    for (int i = r; i > 0; i -= lowb(i)) ret += BIT[i];
    return ret;
}
inline void add(int x, int y) {
    for (int i = x; i <= n; i += lowb(i)) BIT[i] += y;
}

void pushup(int rt) { seg[rt] = min(seg[lson], seg[rson]); }
void pushdown(int rt) {
    if (lazy[rt] == 0) return;
    lazy[lson] += lazy[rt];
    lazy[rson] += lazy[rt];
    seg[lson] += lazy[rt];
    seg[rson] += lazy[rt];
    lazy[rt] = 0;
}
void build(int l, int r, int rt) {
    lazy[rt] = 0;
    if (l == r) {
        seg[rt] = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, lson);
    build(m + 1, r, rson);
    pushup(rt);
}
void update(int L, int R, int l, int r, int rt) {  // L R 是要更新的区间
    if (seg[rt] == 1) {
        seg[rt] = INF;
        if (l == r) {
            seg[rt] = a[l];
            add(l, 1);
            return;
        }
        pushdown(rt);
        int m = (l + r) >> 1;
        if (L <= m) update(L, R, l, m, lson);
        if (m < R) update(L, R, m + 1, r, rson);
        pushup(rt);
        return;
    }
    if (L <= l && r <= R) {
        lazy[rt]--;
        seg[rt]--;
        return;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, l, m, lson);
    if (m < R) update(L, R, m + 1, r, rson);
    pushup(rt);
}

int main() {
// /*
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    // */
    std::ios::sync_with_stdio(false);

    while (~scanf("%d%d", &n, &q)) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            BIT[i] = 0;
        }
        build(1, n, 1);
        char op[10];
        for (int i = 0, l, r; i < q; i++) {
            scanf("%s%d%d", op, &l, &r);
            // printf("%s  %d  %d\n", op, l, r);
            // /*
            if (op[0] == 'a') {
                update(l, r, 1, n, 1);
            } else {
                printf("%d\n", query(l, r));
            }
            // */
        }
    }
}