// Life Forms, POJ3294

/*Sample Input
3
abcdefg
bcdefgh
cdefghi
3
xxx
yyy
zzz
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
    bool vis[100];
    clr(vis, 0);
    int t = N >> 1;
    int cnt = 0;
    for (int i = begin; i <= end; i++)
    {
        if (!vis[id[sa[i]]])
            vis[id[sa[i]]] = true, cnt++;
        if (cnt > t) return true;
    }
    return false;
}

vector<int> v;
bool ok(int k, int n)
{
    bool flag = false;
    int begin = 0, end = 0;
    for (int i = 1; i <= n; i++)
    {
        if (height[i] >= k)
            end++;
        else
        {
            if (solve(begin, end))
            {
                if (!flag) v.clear();
                flag = true;
                v.pb(sa[begin]);
            }
            begin = end = i;
        }
    }
    if (begin < end && solve(begin, end))
    {
        if (!flag) v.clear();
        flag = true;
        v.pb(sa[begin]);
    }
    return flag;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    bool flag = 0;
    char S[105][1005];
    while (~scanf("%d", &N) && N)
    {
        flag ? puts("") : flag = 1;
        for (int i = 0; i < N; i++)
            scanf("%s", S[i]);
        int n = 0;
        int L = 1, R = 0;
        for (int i = 0; i < N; i++)
        {
            int len = strlen(S[i]);
            R = max(R, len);
            for (int j = 0; j < len; j++)
                id[n] = i, s[n++] = S[i][j] - 'a' + 100;
            s[n++] = i;
        }
        build_sa(126, n - 1);
        int ans = 0;
        while (L <= R)
        {
            int mid = (L + R) >> 1;
            if (ok(mid, n))
                ans = mid, L = mid + 1;
            else
                R = mid - 1;
        }
        if (ans == 0)
            puts("?");
        else
        {
            for (int i = 0; i < v.size(); i++)
            {
                for (int j = 0; j < ans; j++)
                    printf("%c", s[v[i] + j] - 100 + 'a');
                puts("");
            }
        }
    }
    return 0;
}
