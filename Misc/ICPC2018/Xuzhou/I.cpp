//ybmj
#include <bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define lson_len (len - (len >> 1))
#define rson_len (len >> 1)
#define pb(x) push_back(x)
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define my_unique(a) a.resize(distance(a.begin(), unique(a.begin(), a.end())))
#define my_sort_unique(c) (sort(c.begin(), c.end())), my_unique(c)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const int maxn = 1e6 + 5;
char s[maxn];
char ans[maxn];
int main()
{
// /*
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    // */
    std::ios::sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        char L[5];
        scanf("%s", L);
        scanf("%s", s);
        int len = strlen(s);
        int sz = 0;
        for (int i = 0; i < len; i++)
        {
            int tmp = abs(L[0] - s[i]);
            if (tmp < 10)
            {
                ans[sz++] = '0';
                ans[sz++] = tmp + '0';
            }
            else
            {
                ans[sz++] = '0' + tmp / 10;
                ans[sz++] = '0' + tmp % 10;
            }
        }
        ans[sz] = '\0';
        // printf("%s\n",ans);
        int t = 0;
        while (t < sz)
        {
            if (ans[t] == '0')
                t++;
            else
                break;
        }
        int out = sz - t;
        out = max(1, out);
        printf("%d\n", out);
    }
}