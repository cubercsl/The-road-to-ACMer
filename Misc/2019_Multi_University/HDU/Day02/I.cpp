#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20;
char s[N], str[N << 1];
int p[N << 1];
void Manacher(char s[], int n)
{
    str[0] = '$', str[1] = '#';
    for (int i = 0; i < n; i++) str[(i << 1) + 2] = s[i], str[(i << 1) + 3] = '#';
    n = 2 * n + 2;
    str[n] = 0;
    int mx = 0, id;
    for (int i = 1; i < n; i++)
    {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (str[i - p[i]] == str[i + p[i]]) p[i]++;
        if (p[i] + i > mx) mx = p[i] + i, id = i;
    }
}
struct Palindromic_Tree
{
    int ch[N][26], f[N], len[N], s[N];
    long long cnt[N]; // 结点表示的本质不同的回文串的个数(调用count()后)
    int num[N];       // 结点表示的最长回文串的最右端点为回文串结尾的回文串个数
    int begin[N], end[N];
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
        end[last] = n;
        begin[last] = end[last] - len[last] + 1;
        cnt[last]++;
    }
    void count()
    {
        for (int i = sz - 1; ~i; i--) cnt[f[i]] += cnt[i];
    }
    long long ans[N];
    void solve(int l, int r, long long cnt)
    {
        --r, --l;
        int m = l + r >> 1;
        int x = m - l + 1;
        int L = l * 2 + 2;
        int R = m * 2 + 2;
        int pos = L + R >> 1;
        if (p[pos] - 1 >= x)
            ans[r - l + 1] += cnt;
    }
    void solve()
    {
        for (int i = 1; i <= n; i++) ans[i] = 0;
        for (int i = 2; i < sz; i++) solve(begin[i], end[i], cnt[i]);
        for (int i = 1; i <= n; i++) printf("%lld%c", ans[i], " \n"[i == n]);
    }
} pam;

int main()
{
    while (~scanf("%s", s))
    {
        pam.init();
        int n = strlen(s);
        Manacher(s, n);
        for (int i = 0; i < n; i++) pam.add(s[i] - 'a');
        pam.count();
        pam.solve();
    }
}