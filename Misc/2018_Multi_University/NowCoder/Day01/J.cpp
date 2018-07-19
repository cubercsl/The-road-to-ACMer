#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 18;
 
int n, q;
int cnt = 0;
struct Node {
    int l, r, sum;
} p[maxn * 40];
 
int la[maxn];
 
int a[maxn];
int root[maxn];
 
int build(int l, int r) {
    int nc = ++cnt;
    p[nc].sum = 0;
    p[nc].l = p[nc].r = 0;
    if (l == r) return nc;
    int m = l + r >> 1;
    p[nc].l = build(l, m);
    p[nc].r = build(m + 1, r);
    return nc;
}
 
int update(int pos, int c, int v, int l, int r) {
    int nc = ++cnt;
    p[nc] = p[c];
    p[nc].sum += v;
    if (l == r) return nc;
    int m = l + r >> 1;
    if (m >= pos) {
        p[nc].l = update(pos, p[c].l, v, l, m);
    } else {
        p[nc].r = update(pos, p[c].r, v, m + 1, r);
    }
    return nc;
}
 
int query(int pos, int c, int l, int r) {
    if (l == r) return p[c].sum;
    int m = l + r >> 1;
    if (m >= pos) {
        return p[p[c].r].sum + query(pos, p[c].l, l, m);
 
    } else
        return query(pos, p[c].r, m + 1, r);
}
 
int main() {
    while (~scanf("%d%d", &n, &q)) {
        cnt = 0;
        memset(la, -1, sizeof la);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
        }
        for (int i = 1; i <= n; ++i) {
            a[n + i] = a[i];
        }
        int m = n;
        n <<= 1;
        root[0] = build(1, n);
        // cerr << n << endl;
        for (int i = 1; i <= n; ++i) {
            int v = a[i];
            if (la[v] == -1) {
                root[i] = update(i, root[i - 1], 1, 1, n);
            } else {
                int t = update(la[v], root[i - 1], -1, 1, n);
                root[i] = update(i, t, 1, 1, n);
            }
            la[v] = i;
        }
        while (q--) {
            int x, y;
            scanf("%d %d", &x, &y);
            x += m;
            swap(x, y);
            // cerr << x << " " << y << endl;
            printf("%d\n", query(x, root[y], 1, n));
        }
    }
    return 0;
}