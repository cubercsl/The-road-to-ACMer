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
#define first fi
#define second se
#define my_unique(a) a.resize(distance(a.begin(), unique(a.begin(), a.end())))
#define my_sort_unique(c) (sort(c.begin(), c.end())), my_unique(c)
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
char Min[15], Max[15], tmp[15];
int sz;
void dfs1(int pos, int k) {
    if (pos == sz || k == 0) {
        // if (strcmp(Min, tmp) > 0) strcpy(Min, tmp);
        if (strcmp(Max, tmp) < 0) strcpy(Max, tmp);
        return;
    };
    char x = '0';
    for (int i = pos + 1; i < sz; i++) {
        x = max(x, tmp[i]);
    }
    dfs1(pos + 1, k);
    for (int i = pos + 1; i < sz; i++) {
        if (tmp[i] == x) {
            swap(tmp[i], tmp[pos]);
            dfs1(pos + 1, k - 1);
            swap(tmp[i], tmp[pos]);
        }
    }
}
void dfs2(int pos, int k) {
    if (pos == sz || k == 0) {
        if (strcmp(Min, tmp) > 0) strcpy(Min, tmp);
        // if (strcmp(Max, tmp) < 0) strcpy(Max, tmp);
        return;
    };
    char x = '9';
    for (int i = pos + 1; i < sz; i++) {
        if (pos == 0 && tmp[i] == '0') continue;
        x = min(x, tmp[i]);
    }
    dfs2(pos + 1, k);
    for (int i = pos + 1; i < sz; i++) {
        if (tmp[i] == x) {
            swap(tmp[i], tmp[pos]);
            dfs2(pos + 1, k - 1);
            swap(tmp[i], tmp[pos]);
        }
    }
}
int main() {
// /*
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    // */
    std::ios::sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    while (T--) {
        char s[15];
        int k;
        scanf("%s%d", s, &k);
        sz = strlen(s);
        for (int i = 0; i <= sz; i++)
            Min[i] = s[i], Max[i] = s[i], tmp[i] = s[i];
        dfs1(0, k);
        for (int i = 0; i <= sz; i++) tmp[i] = s[i];
        dfs2(0, k);
        printf("%s %s\n", Min, Max);
    }
}