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
const int maxn = 1e4 + 5;
char op[maxn][10];
bool vis[maxn][260];
int add[maxn], val[maxn], nxt[maxn];

int getpos(int i, int& foo) {
    if (!strcmp(op[i], "add")) {
        foo = (foo + add[i]) % 256;
        return i + 1;
    } else if (!strcmp(op[i], "beq")) {
        if (foo == val[i])
            return nxt[i];
        else
            return i + 1;
    } else if (!strcmp(op[i], "bne")) {
        if (foo != val[i])
            return nxt[i];
        else
            return i + 1;
    } else if (!strcmp(op[i], "blt")) {
        if (foo < val[i])
            return nxt[i];
        else
            return i + 1;
    } else {
        if (foo > val[i])
            return nxt[i];
        else
            return i + 1;
    }
}
int main() {
    //	/*
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    //	*/
    std::ios::sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%s", op[i]);
            if (!strcmp(op[i], "add")) {
                scanf("%d", &add[i]);
            } else {
                scanf("%d%d", &val[i], &nxt[i]);
            }
        }
        bool flag = true;
        int foo = 0;
        clr(vis, 0);
        int i = 1;
        while (i <= n) {
            if (vis[i][foo]) {
                flag = false;
                break;
            }
            vis[i][foo] = 1;
            i = getpos(i, foo);
        }
        if (flag)
            puts("Yes");
        else
            puts("No");
    }
}