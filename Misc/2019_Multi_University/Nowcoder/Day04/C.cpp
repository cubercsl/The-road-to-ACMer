#include <bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
 
const int maxn = 3e6 + 6;
typedef long long ll;
ll pre[maxn];
int a[maxn], b[maxn];
int L[maxn], R[maxn];
 
int st[maxn];
int stc;
 
void init(int n) {
  stc = 0;
  for (int i = 1; i <= n; i++) {
    while (stc && a[i] <= a[st[stc - 1]]) --stc;
    if (!stc)
      L[i] = 1;
    else
      L[i] = st[stc - 1] + 1;
    st[stc++] = i;
  }
  stc = 0;
  for (int i = n; i > 0; i--) {
    while (stc && a[i] <= a[st[stc - 1]]) --stc;
    if (!stc)
      R[i] = n;
    else
      R[i] = st[stc - 1] - 1;
    st[stc++] = i;
  }
}
 
ll Max[maxn << 2], Min[maxn << 2];
 
void build(int l, int r, int rt) {
  if (l == r) {
    Max[rt] = Min[rt] = pre[l];
    return;
  }
  int m = l + r >> 1;
  build(l, m, lson);
  build(m + 1, r, rson);
  Max[rt] = max(Max[lson], Max[rson]);
  Min[rt] = min(Min[lson], Min[rson]);
}
ll queryMax(int l, int r, int rt, int L, int R) {
  if (L <= l && R >= r) return Max[rt];
  ll ret = -1e18;
  int m = l + r >> 1;
  if (L <= m) ret = queryMax(l, m, lson, L, R);
  if (m + 1 <= R) ret = max(ret, queryMax(m + 1, r, rson, L, R));
  return ret;
}
ll queryMin(int l, int r, int rt, int L, int R) {
  if (L <= l && R >= r) return Min[rt];
  ll ret = 1e18;
  int m = l + r >> 1;
  if (L <= m) ret = queryMin(l, m, lson, L, R);
  if (m + 1 <= R) ret = min(ret, queryMin(m + 1, r, rson, L, R));
  return ret;
}
int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) scanf("%d", b + i), pre[i] = pre[i - 1] + b[i];
  build(0, n, 1);
  init(n);
  // for (int i = 1; i <= n; i++) printf("%d %d\n", L[i], R[i]);
  ll ans = -1e18;
  for (int i = 1; i <= n; i++) {
    ll tmp = 0;
    if (a[i] > 0) {
      tmp = queryMax(0, n, 1, i, R[i]) - queryMin(0, n, 1, L[i] - 1, i - 1);
    } else if (a[i] < 0) {
      tmp = queryMin(0, n, 1, i, R[i]) - queryMax(0, n, 1, L[i] - 1, i - 1);
    }
    ans = max(ans, 1LL * a[i] * tmp);
  }
  printf("%lld\n", ans);
}
