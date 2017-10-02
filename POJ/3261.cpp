// Milk Patterns, POJ3261

/*Sample Input
8 2
1
2
3
2
3
2
3
1
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 2e4 + 5;
int s[maxn];
int sa[maxn], t[maxn], t2[maxn], c[maxn], rnk[maxn], height[maxn];

void build_sa(int m, int n)
{
    n++;
    int *x = t, *y = t2;
    for (int i = 0; i < m; i++) c[i] = 0;
    for (int i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (int i = 1; i < m; i++) c[i] += c[i - 1];
    for (int i = n - 1; ~i; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1)
    {
        int p = 0;
        for (int i = n - k; i < n; i++) y[p++] = i;
        for (int i = 0; i < n; i++)
            if (sa[i] >= k) y[p++] = sa[i] - k;
        for (int i = 0; i < m; i++) c[i] = 0;
        for (int i = 0; i < n; i++) c[x[y[i]]]++;
        for (int i = 0; i < m; i++) c[i] += c[i - 1];
        for (int i = n - 1; ~i; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n) break;
        m = p;
    }
    int k = 0;
    for (int i = 0; i < n; i++) rnk[sa[i]] = i;
    for (int i = 0; i < n; i++)
    {
        if (k) k--;
        int j = sa[rnk[i] - 1];
        while (s[i + k] == s[j + k]) k++;
        height[rnk[i]] = k;
    }
}

bool ok(int mid, int n, int k)
{
    int cnt = 1;
    for (int i = 2; i <= n; i++)
    {
        if (height[i] >= mid)
            cnt++;
        else
            cnt = 1;
        if (cnt >= k) return true;
    }
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, k, tmp;
    while (~scanf("%d%d", &n, &k))
    {
        int m = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            s[i] = tmp;
            m = max(m, tmp + 1);
        }
        s[n] = 0;

        build_sa(m, n);
        int L = 1, R = n, ans;
        while (L <= R)
        {
            int mid = (L + R) >> 1;
            if (ok(mid, n, k))
                ans = mid, L = mid + 1;
            else
                R = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
