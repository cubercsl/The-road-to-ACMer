#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 17;
char buf[maxn];

typedef long long ll;
struct SAM
{
    int len[maxn << 1], link[maxn << 1], ch[maxn << 1][26];
    int sz, rt, last;
    int newnode(int x = 0)
    {
        len[sz] = x;
        link[sz] = -1;
        memset(ch[sz], -1, sizeof(ch[sz]));
        return sz++;
    }
    void init() { sz = last = 0, rt = newnode(); }
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
    int topcnt[maxn], topsam[maxn << 1];
    void sort()
    { // 加入串后拓扑排序
        memset(topcnt, 0, sizeof(topcnt));
        for (int i = 0; i < sz; i++) topcnt[len[i]]++;
        for (int i = 0; i < maxn - 1; i++) topcnt[i + 1] += topcnt[i];
        for (int i = 0; i < sz; i++) topsam[--topcnt[len[i]]] = i;
    }
    int dp[maxn];
    void solve(int a, int b)
    {
        for (int i = 0; i < sz; i++) dp[i] = 0;
        int u = 0;
        for (int i = 0; buf[i]; i++) dp[u = ch[u][buf[i] - 'A']] = 1;
        for (int i = sz - 1; ~i; i--)
        {
            int u = topsam[i];
            if (~link[u]) dp[link[u]] += dp[u];
        }
        ll ans = 0;
        for (int i = 1; i < sz; i++)
            if (dp[i] >= a && dp[i] <= b) ans += len[i] - len[link[i]];
        printf("%lld\n", ans);
    }
} sam;

int main()
{
    int a, b;
    while (~scanf("%s%d%d", buf, &a, &b))
    {
        sam.init();
        for (int i = 0; buf[i]; i++) sam.extend(buf[i] - 'A');
        sam.sort();
        sam.solve(a, b);
    }
}