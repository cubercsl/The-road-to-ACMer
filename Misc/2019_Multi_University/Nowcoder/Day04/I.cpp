#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 19;
struct Suffix_Array
{
    char s[maxn];
    int sa[maxn], t[maxn], t2[maxn], c[maxn], rank[maxn], height[maxn];
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
            for (int i = 1; i < m; i++) c[i] += c[i - 1];
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
        for (int i = 0; i <= n; i++) rank[sa[i]] = i;
        for (int i = 0; i < n; i++)
        {
            if (k) k--;
            int j = sa[rank[i] - 1];
            while (s[i + k] == s[j + k]) k++;
            height[rank[i]] = k;
        }
    }

    int dp[maxn][30];
    void initrmq(int n)
    {
        for (int i = 1; i <= n; i++)
            dp[i][0] = height[i];
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
                dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
    }
    int rmq(int l, int r)
    {
        int k = 31 - __builtin_clz(r - l + 1);
        return min(dp[l][k], dp[r - (1 << k) + 1][k]);
    }
    int lcp(int a, int b)
    {
        a = rank[a], b = rank[b];
        if (a > b) swap(a, b);
        return rmq(a + 1, b);
    }
    //
    long long solve(int n, int sz)
    {
        long long ans = 1LL * sz * (sz + 1) / 2;
        for (int i = 1; i <= sz; i++) ans -= height[i];
        ans -= 1LL * n * n + 2LL * n + 1;
        return ans;
    }
} sa;

struct Palindromic_Tree
{
    int ch[maxn][26], f[maxn], len[maxn], s[maxn];
    int cnt[maxn]; // 结点表示的本质不同的回文串的个数(调用count()后)
    int num[maxn]; // 结点表示的最长回文串的最右端点为回文串结尾的回文串个数
    int last, sz, n;
    int newnode(int x)
    {
        memset(ch[sz], 0, sizeof(ch[sz]));
        cnt[sz] = num[sz] = 0, len[sz] = x;
        return sz++;
    }
    void init()
    {
        sz = 0;
        newnode(0), newnode(-1);
        last = n = 0, s[0] = -1, f[0] = 1;
    }
    int get_fail(int u)
    {
        while (s[n - len[u] - 1] != s[n]) u = f[u];
        return u;
    }
    void add(int c)
    { // c-='a'
        s[++n] = c;
        int u = get_fail(last);
        if (!ch[u][c])
        {
            int np = newnode(len[u] + 2);
            f[np] = ch[get_fail(f[u])][c];
            num[np] = num[f[np]] + 1;
            ch[u][c] = np;
        }
        last = ch[u][c];
        cnt[last]++;
    }
    void count()
    {
        for (int i = sz - 1; ~i; i--) cnt[f[i]] += cnt[i];
    }
} pam;

int main()
{
    scanf("%s", sa.s);
    pam.init();
    int n = strlen(sa.s);
    for (int i = 0; sa.s[i]; i++) pam.add(sa.s[i] - 'a');
    sa.s[n] = '$';
    for (int i = 0, j = n - 1; i < n; i++, j--) sa.s[n + 1 + i] = sa.s[j];
    sa.s[n * 2 + 1] = '\0';
    sa.build_sa(128, n * 2 + 1);
    long long p = sa.solve(n, n * 2 + 1);

    // cerr << ans << endl;
    // cerr << sam.query(1) << endl;
    // cerr << pam.sz << endl;
    long long q = pam.sz - 2;
    printf("%lld\n", (p + q) / 2);
}