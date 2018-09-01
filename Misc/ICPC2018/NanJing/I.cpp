#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int N = 1 << 21;

typedef long long ll;
ll P[N];

struct Palindromic_Tree
{
    int ch[N][10], f[N], cnt[N], len[N], s[N], val[N];
    int last, sz, n;
    int newnode(int x)
    {
        memset(ch[sz], 0, sizeof(ch[sz]));
        cnt[sz] = 0, len[sz] = x;
        val[sz] = 0;
        return sz++;
    }
    void init()
    {
        sz = 0;
        newnode(0), newnode(-1);
        last = 0, n = 0, s[0] = -1, f[0] = 1;
    }
    int get_fail(int u)
    {
        while (s[n - len[u] - 1] != s[n]) u = f[u];
        return u;
    }
    void add(int c)
    {
        s[++n] = c;
        int u = get_fail(last);
        if (!ch[u][c])
        {
            int np = newnode(len[u] + 2);
            f[np] = ch[get_fail(f[u])][c];
            ch[u][c] = np;
            val[np] = ((P[len[u]] * c % mod + val[u]) * 10 + c) % mod;
        }
        last = ch[u][c];
        cnt[last]++;
    }
    ll count()
    {
        ll ans = 0;
        // for (int i = sz - 1; ~i; i--) cnt[f[i]] += cnt[i];
        for (int i = 0; i < sz; i++) (ans += val[i]) %= mod;
        return ans;
    }
} gao;

char s[N];

int main()
{
    P[0] = 1;
    for (int i = 1; i < N; i++) P[i] = P[i - 1] * 10 % mod;
    gao.init();
    scanf("%s", s);
    for (int i = 0; s[i]; i++) gao.add(s[i] - '0');
    printf("%lld\n", gao.count());
}