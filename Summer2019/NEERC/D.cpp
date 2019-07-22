#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 17;
struct SAM
{
    int len[maxn << 1], link[maxn << 1], ch[maxn << 1][26];
    int num[maxn << 1];
    int sz, rt, last;
    int newnode(int x = 0)
    {
        len[sz] = x;
        link[sz] = -1;
        memset(ch[sz], -1, sizeof(ch[sz]));
        return sz++;
    }
    void init() { sz = last = 0, rt = newnode(); }
    void reset() { last = 0; }
    int extend(int c)
    {
        int np = newnode(len[last] + 1);
        int p;
        for (p = last; ~p && ch[p][c] == -1; p = link[p]) ch[p][c] = np;
        if (p == -1)
            link[np] = rt;
        else
        {
            int q = ch[p][c];
            if (len[p] + 1 == len[q])
                link[np] = q;
            else
            {
                int nq = newnode(len[p] + 1);
                memcpy(ch[nq], ch[q], sizeof(ch[q]));
                link[nq] = link[q], link[q] = link[np] = nq;
                for (; ~p && ch[p][c] == q; p = link[p]) ch[p][c] = nq;
            }
        }
        last = np;
        return ~link[np] ? len[np] - len[link[np]] : len[np];
    }
} sam;

typedef long long ll;
char s[maxn];
ll ans[maxn], d[maxn];

int main()
{
    scanf("%s", s + 1);
    sam.init();
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        ans[i] = sam.extend(s[i] - 'a') + ans[i - 1];
    for (int i = 1; i <= n; i++)
    {
        int t = sam.extend(s[i] - 'a');
        ans[i + n] = t + ans[n + i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        int t = sam.extend(s[i] - 'a');
        ans[i + 2 * n] = t + ans[i + 2 * n - 1];
        d[i] = t + d[i - 1];
    }
    int x;
    scanf("%d", &x);
    if (x <= 3 * n)
        printf("%lld\n", ans[x]);
    else
    {
        int k = x / n, p = x % n;
        printf("%lld\n", ans[3 * n] + d[n] * (k - 3) + d[p]);
    }
}