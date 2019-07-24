#include <bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define my_unique(a) a.resize(distance(a.begin(), unique(a.begin(), a.end())))
#define my_sort_unique(c) (sort(c.begin(), c.end())), my_unique(c)
const int INF = 0x3f3f3f3f;
const int maxn = 3e5 + 5;
int a[maxn];

struct Node {
  int x, bid, sid;
  Node(int x = 0, int bid = 0, int sid = 0) : x(x), bid(bid), sid(sid) {}
} seg[maxn << 2];

void build(int l, int r, int rt) {
  seg[rt].x = seg[rt].bid = 0;
  seg[rt].sid = INF;
  if (l == r) return;
  int m = l + r >> 1;
  build(l, m, lson);
  build(m + 1, r, rson);
}
Node MAX(const Node& a, const Node& b) {
  if (a.x > b.x) return a;
  if (a.x < b.x) return b;
  return Node(a.x, max(a.bid, b.bid), min(a.sid, b.sid));
}
inline void pushup(int rt) { seg[rt] = MAX(seg[lson], seg[rson]); }
void update(int l, int r, int rt, int p, int x, int id) {
  if (l == r) {
    seg[rt] = MAX(seg[rt], Node(x, id, id));
    return;
  }
  int m = l + r >> 1;
  if (p <= m)
    update(l, m, lson, p, x, id);
  else
    update(m + 1, r, rson, p, x, id);
  pushup(rt);
}
Node query(int l, int r, int rt, int L, int R) {
  if (L > R) return Node(0, 0, INF);
  if (L <= l && R >= r) return seg[rt];
  int m = l + r >> 1;
  Node ret(-1, -1, 1e9);
  if (L <= m) ret = MAX(ret, query(l, m, lson, L, R));
  if (m + 1 <= R) ret = MAX(ret, query(m + 1, r, rson, L, R));
  return ret;
}

vector<int> num;
inline int getid(int x) {
  return lower_bound(num.begin(), num.end(), x) - num.begin() + 1;
}

int dp[2][maxn];
int pmax[2][maxn], pmin[2][maxn];
void solve(int n) {
  build(1, n, 1);
  for (int i = 1; i <= n; i++) {
    int id = getid(a[i]);
    Node tmp = query(1, n, 1, 1, id - 1);
    dp[0][i] = tmp.x + 1;
    pmax[0][i] = tmp.bid;
    pmin[0][i] = tmp.sid;
    update(1, n, 1, id, dp[0][i], i);
  }

  build(1, n, 1);
  for (int i = n; i > 0; i--) {
    int id = getid(a[i]);
    Node tmp = query(1, n, 1, 1, id - 1);
    dp[1][i] = tmp.x + 1;
    pmax[1][i] = tmp.bid;
    pmin[1][i] = tmp.sid;
    update(1, n, 1, id, dp[1][i], i);
  }
  int Max = 0;
  for (int i = 1; i <= n; i++) Max = max(Max, dp[0][i] + dp[1][i] - 1);

  vector<int> ans[2];
  for (int i = 1; i <= n; i++) {
    if (dp[0][i] + dp[1][i] - 1 == Max) {
      int u = i;
      while (u > 0 && u <= n) {
        ans[0].push_back(u);
        u = pmin[0][u];
      }

      u = pmin[1][i];
      while (u > 0 && u <= n) {
        ans[0].push_back(u);
        u = pmin[1][u];
      }
      break;
    }
  }
  for (int i = n; i > 0; i--) {
    if (dp[0][i] + dp[1][i] - 1 == Max) {
      int u = i;
      while (u > 0 && u <= n) {
        ans[1].push_back(u);
        u = pmax[0][u];
      }

      u = pmax[1][i];
      while (u > 0 && u <= n) {
        ans[1].push_back(u);
        u = pmax[1][u];
      }
      break;
    }
  }
  for (int i = 0; i < 2; i++) {
    sort(ans[i].begin(), ans[i].end());
    for (int j = 0; j < ans[i].size(); j++) {
      if (j)
        printf(" %d", ans[i][j]);
      else
        printf("%d", ans[i][j]);
    }
    puts("");
  }
}
int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);
  int n;
  while (~scanf("%d", &n)) {
    num.clear();
    for (int i = 1; i <= n; i++) scanf("%d", a + i), num.push_back(a[i]);
    my_sort_unique(num);
    solve(n);
  }
}