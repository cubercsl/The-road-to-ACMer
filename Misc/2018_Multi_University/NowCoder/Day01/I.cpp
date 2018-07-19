#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 19;
struct SAM
{
    int len[maxn << 1], link[maxn << 1], ch[maxn << 1][3];
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
    void extend(int c)
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
    }
    long long query()
    {
        long long ans = 0;
        for (int i = 1; i < sz; i++) ans += len[i] - len[link[i]];
        return ans;
    }
} sam;

char s[maxn];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        scanf("%s", s);
        int f[3] = {0, 1, 2};
        sam.init();
        do
        {
            sam.reset();
            for (int i = 0; s[i]; i++) sam.extend(f[s[i] - 'a']);
        } while (next_permutation(f, f + 3));
        long long ans = sam.query();
        int maxlen = 0, len = 1;
        for (int i = 1; i < n; i++)
            if (s[i] == s[i - 1])
                ++len;
            else
                maxlen = max(maxlen, len), len = 1;
        maxlen = max(maxlen, len);
        printf("%lld\n", (ans - maxlen * 3) / 6 + maxlen);
    }
}