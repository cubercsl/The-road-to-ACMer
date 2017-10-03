// Substrings, POJ1226

/*Sample Input
2
3
ABCD
BCDFF
BRCD
2
rose
orchid
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

int N;
int id[maxn];

bool solve(int begin, int end)
{
    bool vis[105];
    clr(vis, 0);
    for (int i = begin; i <= end; i++)
        vis[id[sa[i]]] = true;
    for (int i = 0; i < N; i++)
        if (!vis[i]) return false;
    return true;
}

bool ok(int k, int n)
{
    int begin = 0, end = 0;
    for (int i = 1; i <= n; i++)
    {
        if (height[i] >= k)
            end++;
        else
        {
            if (solve(begin, end)) return true;
            begin = end = i;
        }
    }
    if (begin < end && solve(begin, end)) return true;
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t;
    char S[105][105];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            scanf("%s", S[i]);
        int n = 0, p = 0, m = 128;
        int L = 1, R = 0, ans = 0;
        for (int i = 0; i < N; i++)
        {
            int len = strlen(S[i]);
            R = max(len, R);
            for (int j = 0; j < len; j++, n++)
                id[n] = i, s[n] = S[i][j];
            s[n++] = m++;
            for (int j = len - 1; ~j; j--, n++)
                id[n] = i, s[n] = S[i][j];
            s[n++] = m++;
        }
        s[--n] = 0;
        build_sa(m, n);
        while (L <= R)
        {
            int mid = (L + R) >> 1;
            if (ok(mid, n))
                ans = mid, L = mid + 1;
            else
                R = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
