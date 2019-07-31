#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int ans[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i += 2) ans[i] = 1;
    int res = 0;
    for (int i = 3; i <= n; i += 2) {
      long long tmp = 1;
      while (tmp <= n && (tmp & i) != 0) tmp <<= 1;
      if (tmp <= n)
        ans[i] = tmp;
      else {
        ans[i] = 1;
        res++;
      }
    }
    printf("%d\n", res);
    for (int i = 2; i < n; i++) printf("%d ", ans[i]);
    printf("%d\n", ans[n]);
  }
}
