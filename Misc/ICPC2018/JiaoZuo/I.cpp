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
#define my_unique(a) a.resize(distance(a.begin(), unique(a.begin(), a.end())))
#define my_sort_unique(c) (sort(c.begin(), c.end())), my_unique(c)
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;

int main() {
    //	/*
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    //	*/
    std::ios::sync_with_stdio(false);
    int a, b, c;
    while (~scanf("%d%d%d", &a, &b, &c)) {
        if ((a % 2 == 0) || (b % 2 == 0) || (c % 2 == 0))
            puts("Yes");
        else
            puts("No");
        /*
        2 1 1
        1 2 1
        1 1 2
        */
        /*
         bool flag = false;
         for (int i = 0; i <= 100; i++) {
             if (flag) break;
             for (int j = 0; j <= 100; j++) {
                 if (flag) break;
                 for (int k = 0; k <= 100; k++) {
                     if (i * 2 + j + k == a && i + j * 2 + k == b &&
                         i + j + k * 2 == c) {
                         flag = true;
                         break;
                     }
                 }
             }
         }
         if (flag)
             printf("Yes\n");
         else
             printf("No\n");
             */
    }
}