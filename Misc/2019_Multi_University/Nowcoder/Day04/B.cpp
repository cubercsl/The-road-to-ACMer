#include <bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
typedef long long ll;
const int maxn = 5e4 + 4;
const int MAX_BASE = 31;
typedef unsigned int uint;
 
struct LB {
  uint basis[MAX_BASE + 1];
  void clear() { memset(basis, 0, sizeof(basis)); }
  void insert(uint x) {
    for (int i = MAX_BASE; i >= 0 && x; i--) {
      if (x >> i & 1) {
        if (basis[i] == 0) {
          basis[i] = x;
          return;
        }
        x ^= basis[i];
      }
    }
  }
  bool check(uint x) {
    for (int i = MAX_BASE; i >= 0 && x; i--) {
      if (x >> i & 1) {
        x ^= basis[i];
      }
    }
    return x == 0;
  }
};
 
LB Merge(LB A, LB B) {
  LB All, C, D;
  All.clear();
  C.clear();
  D.clear();
  for (int i = MAX_BASE; i >= 0; i--) {
    All.basis[i] = A.basis[i];
    D.basis[i] = 1ll << i;
  }
  for (int i = MAX_BASE; i >= 0; i--) {
    if (B.basis[i]) {
      uint v = B.basis[i], k = 0;
      bool can = true;
      for (int j = MAX_BASE; j >= 0; j--) {
        if (v & (1ll << j)) {
          if (All.basis[j]) {
            v ^= All.basis[j];
            k ^= D.basis[j];
          } else {
            can = false;
            All.basis[j] = v;
            D.basis[j] = k;
            break;
          }
        }
      }
 
      if (can) {
        uint v = 0;
        for (int j = MAX_BASE; j >= 0; j--) {
          if (k & (1ll << j)) {
            v ^= A.basis[j];
          }
        }
        C.insert(v);
      }
    }
  }
  // C.build();
  return C;
}
 
LB a[maxn], seg[maxn << 2];
 
inline void pushup(int rt) { seg[rt] = Merge(seg[lson], seg[rson]); }
void build(int l, int r, int rt) {
  if (l == r) {
    seg[rt] = a[l];
    return;
  }
  int m = l + r >> 1;
  build(l, m, lson);
  build(m + 1, r, rson);
  pushup(rt);
}
bool query(int l, int r, int rt, int L, int R, uint x) {
  if (L <= l && R >= r) return seg[rt].check(x);
  int m = l + r >> 1;
  if (L <= m)
    if (query(l, m, lson, L, R, x) == false) return false;
  if (m + 1 <= R)
    if (query(m + 1, r, rson, L, R, x) == false) return false;
  return true;
}
 
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1, sz; i <= n; i++) {
    a[i].clear();
    scanf("%d", &sz);
    for (int j = 0, x; j < sz; j++) {
      scanf("%u", &x);
      a[i].insert(x);
    }
  }
  build(1, n, 1);
  uint x;
  for (int i = 0, l, r; i < m; i++) {
    scanf("%d%d%u", &l, &r, &x);
    if (query(1, n, 1, l, r, x))
      puts("YES");
    else
      puts("NO");
  }
}