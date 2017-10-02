// Common Substrings, POJ3415

/*Sample Input
2
aababaa
abaabaa
1
xx
xx
0
*/

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

const int maxn = 1 << 18;
char s[maxn];
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
    n--;
    int k = 0;
    for (int i = 0; i <= n; i++) rnk[sa[i]] = i;
    for (int i = 0; i < n; i++)
    {
        if (k) k--;
        int j = sa[rnk[i] - 1];
        while (s[i + k] == s[j + k]) k++;
        height[rnk[i]] = k;
    }
}

ll solve(int k, int n, int len, bool flag)
{
    ll ret = 0;
    ll sum[maxn];
    int h[maxn], cnt[maxn];
    sum[0] = h[0] = cnt[0] = 0;
    int top = 0;
    int tmp;
    for (int i = 1; i <= n; i++)
    {
        tmp = 0;
        while (top && h[top] > height[i])
            tmp += cnt[top--];
        if (tmp && height[i] >= k)
        {
            ll Sum = sum[top] + (ll)(height[i] - k + 1) * tmp;
            // printf("push: %lld\n", Sum);
            sum[++top] = Sum, h[top] = height[i], cnt[top] = tmp;
        }
        if ((sa[i] > len) ^ flag)
            h[++top] = INF, cnt[top] = 1;
        else
            ret += sum[top];
    }
    // printf("ret = %lld\n", ret);
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int k;
    while (~scanf("%d", &k) && k)
    {
        scanf("%s", s);
        int len = strlen(s);
        s[len] = '$';
        scanf("%s", s + len + 1);
        int n = strlen(s);
        // printf("%s\n", s);
        build_sa(128, n);
        ll ans = solve(k, n, len, 0) + solve(k, n, len, 1);
        printf("%lld\n", ans);
    }
    return 0;
}
